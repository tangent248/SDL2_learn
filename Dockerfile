FROM ubuntu
RUN apt update -y \
&& apt install clang -y && apt-get install libsdl2-dev -y 
COPY . /app
WORKDIR /app
ENV DISPLAY=:0
RUN clang++ main.cpp -o main -lSDL2 
CMD [ "./main" ]