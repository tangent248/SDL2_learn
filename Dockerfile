# Use an Ubuntu 22.04 base image
FROM ubuntu

# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Update and upgrade the package list, and install necessary packages
RUN apt-get update && apt-get upgrade -y \
    && apt-get install -y make g++ libc6-dev libsdl2-dev libsdl2-image-dev


ENV XDG_RUNTIME_DIR=/run/user/0

# Build the application
RUN make

# Command to run the application
CMD [ "./exe/game" ]
