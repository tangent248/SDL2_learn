FROM didstopia/sdl2 
COPY . /app
WORKDIR /app
RUN g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o main -lSDL2 -ldl -lGL
CMD [ "./main" ]