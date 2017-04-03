rm -rf var
mkdir -p var/gogs
docker build -t git-docker .
docker ps -a | grep "gitserver" | awk '{print $1}' | grep -v "CONT" | xargs -I {} docker stop {} | xargs -I {} docker rm {}
docker run  -d -p 10022:22 -p 10080:3000 -v $PWD/var/gogs:/data --name gitserver git-docker
