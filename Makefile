CMP=gcc
AR=ar

dsa.c:
	$(CMP) -Wextra -Wall -o dsa

clean:
	find . -type f -not -path "./.git/*" -not \( -name "*.c" -o -name "*.h" -o -name "*.md" -o -name "*.gitignore" -o -name "*Makefile" \) -delete
