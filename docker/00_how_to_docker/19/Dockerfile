# our base image
FROM python:2-slim

# install Python modules needed by the Python app
COPY requirements.txt /usr/src/app/
RUN pip install --no-cache-dir -r /usr/src/app/requirements.txt

# copy files required for the app to run
COPY app.py /usr/src/app/

# tell the port number the container should expose
EXPOSE 3000

# run the application
CMD ["python", "/usr/src/app/app.py"]
