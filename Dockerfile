FROM didstopia/sdl2 
COPY . /app
WORKDIR /app
RUN apt-get install make
RUN make && ./exe/game
CMD [ "./exe/game" ]