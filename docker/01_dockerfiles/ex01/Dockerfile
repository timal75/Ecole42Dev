# our base image
FROM debian:latest 

ENV TS_DIRECTORY=/opt/teamspeak

WORKDIR /

RUN apt-get update && apt-get install -y bzip2 wget &&\ 
 	apt-get update && apt-get install -y w3m &&\
	rm -rf /var/lib/apt/lists/* &&\
	wget -q http://dl.4players.de/ts/releases/`echo "$(w3m -dump https://www.teamspeak.com/downloads | grep -m 1 'Server 64-bit ' | awk '{print $NF}')"`\ 
/teamspeak3-server_linux_amd64-`echo "$(w3m -dump https://www.teamspeak.com/downloads | grep -m 1 'Server 64-bit ' | awk '{print $NF}')"`\ 
.tar.bz2 -O /tmp/teamspeak.tar.bz2 &&\
	tar jxf /tmp/teamspeak.tar.bz2 -C /opt &&\
	mv /opt/teamspeak3-server_* ${TS_DIRECTORY}  &&\
	rm /tmp/teamspeak.tar.bz2 &&\
	apt-get purge -y bzip2 w3m wget &&\
	apt-get autoremove -y &&\
	mkdir -p ${TS_DIRECTORY}/config ${TS_DIRECTORY}/logs ${TS_DIRECTORY}/bin &&\
	mkdir -p ${TS_DIRECTORY}/files ${TS_DIRECTORY}/data &&\
	rm -rf /var/lib/apt/lists/*

RUN groupadd -g 503 teamspeak &&\
	useradd -u 503 -g 503 -d ${TS_DIRECTORY} teamspeak &&\
	mkdir /data &&\
	chown -R teamspeak:teamspeak ${TS_DIRECTORY} &&\
	chown -R teamspeak:teamspeak ${TS_DIRECTORY}/config &&\
	chown -R teamspeak:teamspeak ${TS_DIRECTORY}/logs &&\
	chown -R teamspeak:teamspeak ${TS_DIRECTORY}/bin &&\
	chown -R teamspeak:teamspeak ${TS_DIRECTORY}/files &&\
	chown -R teamspeak:teamspeak ${TS_DIRECTORY}/data 

COPY teamspeak ${TS_DIRECTORY}/bin
COPY ts3server.ini ${TS_DIRECTORY}/config

EXPOSE 9987/udp
EXPOSE 30033/tcp
EXPOSE 10011/tcp


WORKDIR ${TS_DIRECTORY}
RUN cd ${TS_DIRECTORY}

USER teamspeak

ENTRYPOINT ["/opt/teamspeak/bin/teamspeak"]
CMD ["inifile=/opt/teamspeak/config/ts3server.ini"]

