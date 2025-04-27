# update_readme.py (Python 코드)

import os
import requests
from datetime import datetime
from typing import Dict, List
import json

class ProblemInfo:
    def __init__(self, number: str, data: Dict):
        self.number = number
        self.title = data.get('titleKo', '')
        self.level = data.get('level', 0)
        self.tags = [tag['key'] for tag in data.get('tags', [])]
        
    def get_difficulty_emoji(self) -> str:
        level_emoji = {
            0: '🌱',  # Unrated
            1: '🥉', 2: '🥉', 3: '🥉', 4: '🥉', 5: '🥉',  # Bronze
            6: '🥈', 7: '🥈', 8: '🥈', 9: '🥈', 10: '🥈',  # Silver
            11: '🥇', 12: '🥇', 13: '🥇', 14: '🥇', 15: '🥇',  # Gold
            16: '💎', 17: '💎', 18: '💎', 19: '💎', 20: '💎',  # Platinum
            21: '👑', 22: '👑', 23: '👑', 24: '👑', 25: '👑',  # Diamond
            26: '🏆', 27: '🏆', 28: '🏆', 29: '🏆', 30: '🏆'   # Ruby
        }
        return level_emoji.get(self.level, '🌱')

def fetch_problem_info(problem_numbers: List[str]) -> Dict[str, ProblemInfo]:
    problems = {}
    
    for i in range(0, len(problem_numbers), 100):
        batch = problem_numbers[i:i+100]
        query = ','.join(batch)
        url = f"https://solved.ac/api/v3/problem/lookup?problemIds={query}"
        
        try:
            response = requests.get(url, headers={'Content-Type': 'application/json'})
            if response.status_code == 200:
                for prob_data in response.json():
                    prob_num = str(prob_data['problemId'])
                    problems[prob_num] = ProblemInfo(prob_num, prob_data)
        except Exception as e:
            print(f"Error fetching problem info: {e}")
            continue
            
    return problems

def collect_problems():
    problems_by_tag = {}
    difficulty_stats = {
        '🥉': 0, '🥈': 0, '🥇': 0,
        '💎': 0, '👑': 0, '🏆': 0
    }
    total_problems = set()
    
    solutions_dir = "Solutions/Baekjoon"
    problem_numbers = []
    
    for item in os.listdir(solutions_dir):
        if item.isdigit():
            problem_numbers.append(item)
    
    problem_info = fetch_problem_info(problem_numbers)
    
    for number in problem_numbers:
        if number in problem_info:
            info = problem_info[number]
            difficulty = info.get_difficulty_emoji()
            
            if number not in total_problems:
                difficulty_stats[difficulty] += 1
                total_problems.add(number)
            
            file_path = f"{number}/{number}.cpp"
            
            problem_data = {
                'number': number,
                'name': info.title,
                'difficulty': difficulty,
                'path': f"Solutions/Baekjoon/{file_path}"
            }
            
            for tag in info.tags:
                if tag not in problems_by_tag:
                    problems_by_tag[tag] = []
                problems_by_tag[tag].append(problem_data)
    
    return problems_by_tag, difficulty_stats, len(total_problems)

def generate_current_focus():
    try:
        with open(".github/scripts/current_focus.json", "r", encoding="utf-8") as f:
            data = json.loads(f.read())
            
        content = """## 📚 Current Focus
<p align="center">"""
        
        for topic in data["topics"]:
            content += f"""
  <a href="{topic['url']}"><img src="https://img.shields.io/badge/{topic['name'].replace(' ', '_')}-{topic['color']}?style=flat-square&logo=TheAlgorithms&logoColor=white"/></a>"""
            
        content += "\n</p>\n"
        return content
    except Exception as e:
        print(f"Error generating current focus: {e}")
        return """## 📚 Current Focus
<p align="center">
  <a href="https://blog.encrypted.gg/936"><img src="https://img.shields.io/badge/Advanced_Stack-FF6B6B?style=flat-square&logo=TheAlgorithms&logoColor=white"/></a>
  <a href="https://blog.encrypted.gg/941"><img src="https://img.shields.io/badge/BFS-00599C?style=flat-square&logo=TheAlgorithms&logoColor=white"/></a>
</p>
"""

def generate_readme():
    problems_by_tag, difficulty_stats, total_count = collect_problems()
    
    readme_content = """<div align="center">

![header](https://capsule-render.vercel.app/api?type=transparent&color=39FF14&height=150&section=header&text=Algorithm%20Study&fontSize=70&animation=fadeIn&fontColor=39FF14&desc=Problem%20Solving%20Repository&descSize=25&descAlignY=75)

## 📊 Current Status
<p align="center">
  <a href="https://solved.ac/profile/khkcejkms1"><img height="180em" src="http://mazassumnida.wtf/api/v2/generate_badge?boj=khkcejkms1"/></a>
</p>

## 🎯 Learning Progress
<p align="center">
  <img src="https://img.shields.io/badge/Data_Structures-007396?style=for-the-badge&logo=java&logoColor=white"/>
  <img src="https://img.shields.io/badge/Algorithms-FF6B6B?style=for-the-badge&logo=TheAlgorithms&logoColor=white"/>
  <img src="https://img.shields.io/badge/Problem_Solving-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
</p>

"""
    
    readme_content += generate_current_focus()
    
    readme_content += "\n## 🏃‍♂️ Problem Solving\n"
    
    readme_content += """### 🏅 Difficulty Stats
<div align="center">

"""
    
    difficulty_names = {
        '🥉': 'Bronze', '🥈': 'Silver', '🥇': 'Gold',
        '💎': 'Platinum', '👑': 'Diamond', '🏆': 'Ruby'
    }
    
    for emoji, name in difficulty_names.items():
        count = difficulty_stats[emoji]
        formatted_text = f"{emoji} {name}".ljust(30)
        readme_content += f"`{formatted_text}` `{count}`\n"
    
    readme_content += f"\n**Total Solved: {total_count} Problems**\n</div>\n\n"
    
    for tag, problems in sorted(problems_by_tag.items()):
        if not problems:
            continue
            
        tag_display = tag.replace('_', ' ').title()
        readme_content += f"""<details>
<summary>{tag_display}</summary>

<div align="center">

"""
        
        sorted_problems = sorted(problems, key=lambda x: (x['difficulty'], x['number']))
        
        for prob in sorted_problems:
            readme_content += f"{prob['difficulty']} [{prob['name']} (BOJ {prob['number']})]({prob['path']})\n\n"
        
        test_path = f"Solutions/DataStructures/_Tests/{tag_display.replace(' ', '')}Test"
        if os.path.exists(test_path):
            readme_content += f"✅ [{tag_display} Implementation Test]({test_path}/{tag.lower()}_test.cpp)\n\n"
        
        readme_content += "</div>\n</details>\n\n"
    
    readme_content += """## 📚 References
<p align="center">
  <a href="https://blog.encrypted.gg/category/강좌/실전%20알고리즘"><img src="https://img.shields.io/badge/BaaaaaaaaaaarkingDog_Algorithm_Lecture-11B48A?style=flat-square&logo=Vimeo&logoColor=white"/></a>
  <a href="https://www.acmicpc.net/"><img src="https://img.shields.io/badge/Baekjoon_Online_Judge-0076C0?style=flat-square&logo=Baidu&logoColor=white"/></a>
</p>

</div>"""
    
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(readme_content)

if __name__ == "__main__":
    generate_readme()
