docker build --no-cache -t teamspeak-docker .
docker ps -a | grep "teamspeakserver" | awk '{print $1}' | grep -v "CONT" | xargs -I {} docker stop {} | xargs -I {} docker rm {} 
docker run  -d --rm --publish=9987:9987/udp --publish=30033:30033/tcp --publish=10011:10011/tcp --name teamspeakserver teamspeak-docker
