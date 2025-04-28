#!/usr/bin/env python

import os
import html
from urllib import parse

HEADER = """#
# 백준, 프로그래머스 문제 풀이 목록
"""

# HTML 코드 부분을 문자열로 포함하고, '📊 Current Status'를 중앙 정렬
CURRENT_STATUS = """
## 📊 Current Status
<p align="center">
  <a href="https://solved.ac/profile/khkcejkms1"><img height="180em" src="http://mazassumnida.wtf/api/v2/generate_badge?boj=khkcejkms1"/></a>
</p>
"""

# References 부분 추가
REFERENCES = """
## 📚 References
<p align="center">
  <a href="https://blog.encrypted.gg/category/강좌/실전%20알고리즘"><img src="https://img.shields.io/badge/BaaaaaaaaaaarkingDog_Algorithm_Lecture-11B48A?style=flat-square&logo=Vimeo&logoColor=white"/></a>
  <a href="https://www.acmicpc.net/"><img src="https://img.shields.io/badge/Baekjoon_Online_Judge-0076C0?style=flat-square&logo=Baidu&logoColor=white"/></a>
</p>
"""

def main():
    content = HEADER + CURRENT_STATUS  # HEADER와 CURRENT_STATUS 합치기
    root_dirs = ["백준", "프로그래머스"]

    for site in root_dirs:
        site_path = os.path.join(".", site)
        if not os.path.isdir(site_path):
            continue

        content += f"\n## 📚 {site}\n"

        for difficulty in sorted(os.listdir(site_path)):
            diff_path = os.path.join(site_path, difficulty)
            if not os.path.isdir(diff_path):
                continue

            content += f"<details>\n<summary><strong>🚀 {difficulty}</strong></summary>\n\n"
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

    content += REFERENCES  # References 추가

    with open("README.md", "w", encoding="utf-8") as fd:
        fd.write(content)

if __name__ == "__main__":
    main()
