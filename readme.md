sdl learn file
docker commands
build - docker build . -t game
windows run :-  
docker run -it -v /run/desktop/mnt/host/wslg/.X11-unix:/tmp/.
X11-unix `               
-v /run/desktop/mnt/host/wslg:/mnt/wslg `
-e DISPLAY=:0 `
-e WAYLAND_DISPLAY=wayland-0 `
-e XDG_RUNTIME_DIR=/mnt/wslg/runtime-dir `
-e PULSE_SERVER=/mnt/wslg/PulseServer `
game
linux run :- 
sudo  docker run -it --env DISPLAY=unix$DISPLAY --privileged  --volume /tmp/.X11-unix:/tmp/.X11-unix game