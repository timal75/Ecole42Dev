cat  /etc/passwd | cut -d : -f1| rev | sort -r | sed '1d' | awk -v skip=2 '{for (i=1;i<skip;i++) {getline}; print -zsh}'  | awk '{printf %s,,-zsh}' | sed 's/,$/./g'
