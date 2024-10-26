FROM ubuntu
RUN apt-get update \
&& DEBIAN_FRONTEND=noninteractive apt-get install -y \
x11-apps \
xterm
RUN apt update -y \
&& apt install clang -y && apt-get install libsdl2-dev -y 
COPY . /app
WORKDIR /app
ENV DISPLAY=:0
RUN clang++ main.cpp -o main -lSDL2 
CMD [ "./main" ]