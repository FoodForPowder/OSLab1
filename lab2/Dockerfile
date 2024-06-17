FROM ubuntu:latest
WORKDIR /app
COPY main.sh .
RUN chmod +x /app/main.sh
VOLUME /shared_volume
CMD ["/app/main.sh"]
