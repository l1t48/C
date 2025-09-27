# Use a GCC base image
FROM gcc:10.5.0

# Set working directory
WORKDIR /app

# Copy all project files
COPY . .

# Install check library for unit testing
RUN apt-get update && apt-get install -y check

# Build the project
RUN make

# Default command
CMD ["./main"]
