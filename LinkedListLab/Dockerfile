FROM gcc:13.3.0

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y make \
    && rm -rf /var/lib/apt/lists/*

RUN make

CMD ["./lab"]
