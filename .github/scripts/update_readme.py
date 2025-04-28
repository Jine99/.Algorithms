#!/usr/bin/env python

import os
import html
from urllib import parse

HEADER = """<div align="center">

![header](https://capsule-render.vercel.app/api?type=transparent&color=39FF14&height=150&section=header&text=Algorithm%20Study&fontSize=70&animation=fadeIn&fontColor=39FF14&desc=Problem%20Solving%20Repository&descSize=25&descAlignY=75)

</div>
"""

# 📊 Current Status 부분을 문자열로 작성
CURRENT_STATUS = """
<div align="center">
  <h2>📊 Current Status</h2>  <!-- 제목을 HTML <h2> 태그로 감싸 크기 조정 -->
</div>
<p align="center">
  <a href="https://solved.ac/profile/khkcejkms1"><img height="180em" src="http://mazassumnida.wtf/api/v2/generate_badge?boj=khkcejkms1"/></a>
</p>
"""

# 📚 References를 중앙 정렬하고 제목을 h2로 크기 조정하는 함수
def add_references_section():
    return """
<div align="center">
  <h2>📚 References</h2>
</div>
<p align="center">
  <a href="https://blog.encrypted.gg/category/강좌/실전%20알고리즘"><img src="https://img.shields.io/badge/BaaaaaaaaaaarkingDog_Algorithm_Lecture-11B48A?style=flat-square&logo=Vimeo&logoColor=white"/></a>
  <a href="https://www.acmicpc.net/"><img src="https://img.shields.io/badge/Baekjoon_Online_Judge-0076C0?style=flat-square&logo=Baidu&logoColor=white"/></a>
</p>
"""

# 난이도별 이모지 매핑
difficulty_emojis = {
    "Bronze": "🥉",
    "Silver": "🥈",
    "Gold": "🥇",
    "Platinum": "💎",
    "Diamond": "👑",
    "Ruby": "🏆"
}

# 사이트 이름을 영문으로 변환할 매핑
site_titles = {
    "백준": "Baekjoon",
    "프로그래머스": "Programmers"
}

def main():
    content = HEADER + CURRENT_STATUS  # HEADER와 CURRENT_STATUS 합치기
    root_dirs = ["백준", "프로그래머스"]

    # 난이도 순서 정의 (브론즈, 실버, 골드 순으로 정렬)
    difficulty_order = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby"]

    for site in root_dirs:
        site_path = os.path.join(".", site)
        if not os.path.isdir(site_path):
            continue

        # 사이트 이름을 영문으로 변환
        site_title = site_titles.get(site, site)  # 딕셔너리에 없으면 원래 폴더 이름 사용
        content += f"\n<div align='center'>\n<h2>📚 {site_title}</h2>\n</div>\n"

        for difficulty in sorted(os.listdir(site_path), key=lambda x: difficulty_order.index(x) if x in difficulty_order else float('inf')):
            diff_path = os.path.join(site_path, difficulty)
            if not os.path.isdir(diff_path):
                continue

            # 난이도별 이모지 추가
            emoji = difficulty_emojis.get(difficulty, "🚀")

            content += f"<details>\n<summary><strong>{emoji} {difficulty}</strong></summary>\n\n"
            content += "| 문제번호 | 문제 | 개념 |\n"
            content += "| -------- | ----- | ---- |\n"

            for problem_folder in sorted(os.listdir(diff_path)):
                prob_path = os.path.join(diff_path, problem_folder)
                if not os.path.isdir(prob_path):
                    continue

                problem_number = problem_folder
                number_part, name_part = ("", problem_folder)

                if '.' in problem_folder:
                    number_part, name_part = problem_folder.split('.', 1)
                    name_part = name_part.strip()

                problem_link = "-"
                concept_links = []

                for file in sorted(os.listdir(prob_path)):
                    if not file.endswith(".md"):
                        continue

                    md_path = parse.quote(os.path.join(prob_path, file))

                    if file == "README.md":
                        if name_part:
                            problem_link = f"[{html.escape(name_part)}]({md_path})"
                        else:
                            problem_link = f"[문제 설명]({md_path})"
                    else:
                        title = html.escape(file[:-3])
                        concept_links.append(f"[{title}]({md_path})")

                display_number = number_part or html.escape(problem_folder)
                display_problem = problem_link
                display_concepts = concept_links

                # 표 작성
                if display_concepts:
                    content += f"| {display_number} | {display_problem} | {display_concepts[0]} |\n"
                    for concept in display_concepts[1:]:
                        content += f"|  |  | {concept} |\n"
                else:
                    content += f"| {display_number} | {display_problem} | - |\n"

            content += "\n</details>\n"

        # 📚 References 섹션 추가
        content += add_references_section()  # References 섹션을 함수로 추가

    with open("README.md", "w", encoding="utf-8") as fd:
        fd.write(content)

if __name__ == "__main__":
    main()
