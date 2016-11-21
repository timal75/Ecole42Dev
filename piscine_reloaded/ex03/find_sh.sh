find . -name "*.sh" -type f -print | rev | cut -d "/" -f1 | rev | cut -d "." -f1
