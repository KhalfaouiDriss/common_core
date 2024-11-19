clone:
	rm -rf common_core && \
        git clone git@github.com:KhalfaouiDriss/common_core.git common_core

push:
	git add . && \
        git status && \
        git commit -m "get_next_line" && \
        git push

re:
	rm -rf common_core && \
        make clone

