docker-compose run web rails new . --force --database=postgresql --skip-bundle
cat > ./config/database.yml <<EOF
development: &default
  adapter: postgresql
  encoding: unicode
  database: myapp_development
  pool: 5
  username: postgres
  password:
  host: db

test:
  <<: *default
  database: myapp_test
EOF
docker-compose build
docker-compose up&
docker-compose run web rake db:create
