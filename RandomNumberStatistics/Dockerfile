# Use an official GCC image
FROM gcc:10.5.0

# Set working directory inside container
WORKDIR /usr/src/app

# Copy your C file into the container
COPY lab.c .

# Compile your C program
RUN gcc -o lab lab.c

# Run the program when the container starts
CMD ["./lab"]
