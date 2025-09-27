# Use GCC base image
FROM gcc:10.5.0

# Set working directory inside container
WORKDIR /app

# Copy all project files into container
COPY . .

# Install make (if not included already)
RUN apt-get update && apt-get install -y make

# Run make to build the program
RUN make

# Default command to run your program
CMD ["./lab"]
