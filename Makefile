#!/usr/bin/env make

VERSION=0.0.1
MAX_MEMORY=5000
PROJECT=memory-hamster
BUILD=${PROJECT}:${VERSION}
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
	docker run -e MAX_MEMORY=${MAX_MEMORY} -it memory-hamster

finish:
	docker run -e WAITTIME=1 -e MAX_MEMORY=${MAX_MEMORY} -it memory-hamster ./finish

publish:
	docker build \
		--build-arg http_proxy=$(http_proxy) \
		--build-arg https_proxy=$(https_proxy) \
		--build-arg no_proxy=$(no_proxy) \
		-f Dockerfile \
		-t ${BUILD} \
		.
	docker tag  $(BUILD) tfluehmann/$(PROJECT):latest
	docker tag  $(BUILD) tfluehmann/${BUILD}
	docker push tfluehmann/memory-hamster:latest
	docker push tfluehmann/memory-hamster:${VERSION}
