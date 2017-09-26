docker-compose run web django-admin.py startproject composeexample .

sed -i.bak '/DATABASES = {/,/^}/d' ./composeexample/settings.py

sed -i.bak '/ALLOWED_HOSTS/d' ./composeexample/settings.py

sed -i.bak '/DEBUG = True$/a \
ALLOWED_HOSTS = ['"'"'*'"'"',]' ./composeexample/settings.py

sed -i.bak '/databases$/a \
DATABASES = { \
    '"'"'default'"'"': { \
        '"'"'ENGINE'"'"': '"'"'django.db.backends.postgresql'"'"', \
        '"'"'NAME'"'"': '"'"'postgres'"'"', \
        '"'"'USER'"'"': '"'"'postgres'"'"', \
        '"'"'HOST'"'"': '"'"'db'"'"', \
        '"'"'PORT'"'"': 5432, \
    } \
} ' ./composeexample/settings.py

docker-compose up
