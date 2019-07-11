#!/usr/bin/env make

MAX_MEMORY=5000
# By default, `make` without arguments runs the first target in the Makefile.
# Hence let's declare it explicitly.
_default:

build:
	docker build \
		--build-arg http_proxy=$(http_proxy) \
		--build-arg https_proxy=$(https_proxy) \
		--build-arg no_proxy=$(no_proxy) \
		-f Dockerfile \
		-t memory-hamster \
		.

run: 
	docker run -e MAX_MEMORY=${MAX_MEMORY}-it memory-hamster

finish:
	docker run -e WAITTIME=1 -e MAX_MEMORY=${MAX_MEMORY} -it memory-hamster ./finish
