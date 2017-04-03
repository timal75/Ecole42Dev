FROM ruby:2.3-slim

RUN apt-get update && apt-get install -y \
  build-essential libpq-dev qt5-default \
  libqt5webkit5-dev \
  nodejs

RUN mkdir -p /opt/app
WORKDIR /opt/app

COPY Gemfile Gemfile.lock ./
RUN bundle install

COPY . /opt/app

EXPOSE 3000

ENTRYPOINT ["bundle", "exec"]

CMD ["rails", "server", "-p" , "3000", "-b", "0.0.0.0"]
