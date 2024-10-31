FROM didstopia/sdl2 
COPY . /app
WORKDIR /app
RUN g++ main.cpp -o main -I./glad/include  -lSDL2 -std=c++11
CMD [ "./main" ]