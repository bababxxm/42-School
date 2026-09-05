FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	curl \
	git \
	zsh \
	make \
	build-essential \
	docker.io \
	vim \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /home/sklaokli/42/common-core/r05/inception/root

ENTRYPOINT ["zsh"]