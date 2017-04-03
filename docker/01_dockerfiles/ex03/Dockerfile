# our base image
FROM debian:latest

ENV HOMEDIR=/home/git
ENV GOPATH=/home/git/go
ENV GOROOT=$HOMEDIR/local/go
ENV PATH="$PATH:$GOROOT/bin:$GOPATH/bin"

RUN groupadd -g 503 git &&\
	useradd -u 503 -g 503 -d /home/git git

RUN mkdir -p /home/git/local/go
RUN apt-get update && apt-get install -y bzip2 wget git gcc libpam0g-dev &&\
    wget -q https://storage.googleapis.com/golang/go1.7.4.linux-amd64.tar.gz \
    -O /home/git/go1.7.4.linux-amd64.tar.gz &&\
    tar -C /home/git/local -xzf /home/git/go1.7.4.linux-amd64.tar.gz

COPY startup $HOMEDIR/startup

RUN mkdir -p ${GOPATH}/src/github.com/gogits &&\
    mkdir -p ${GOPATH}/src/github.com/gogits &&\
    chown -R git:git /home/git &&\
    cd ${GOPATH}/src/github.com/gogits &&\
    git clone --depth=1 -b develop https://github.com/gogits/gogs gogs &&\
    chown -R git:git /home/git &&\
    cd ${GOPATH}/src/github.com/gogits/gogs &&\
    go build &&\
    rm -rf /home/git/go/pkg/linux_amd64/github.com/gogits/gogs/ &&\
    go get -u -tags "sqlite pam cert" github.com/gogits/gogs &&\
    cd $GOPATH/src/github.com/gogits/gogs &&\
    go build -tags "sqlite pam cert" &&\
    chown -R git:git /home/git

EXPOSE 3000
EXPOSE 22

#USER git
CMD ["/bin/sh", "-c", "su git", "/home/git/go/src/github.com/gogits/gogs/gogs web"]
