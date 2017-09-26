FROM ruby:2.3.4

RUN apt-get update && apt-get install -y nodejs && gem install rails -v 4.2.7
RUN mkdir -p /opt/app

ONBUILD WORKDIR /opt/app

ONBUILD COPY . /opt/app

ONBUILD RUN bundle install && rake db:migrate && rake db:seed

ONBUILD EXPOSE 3000
