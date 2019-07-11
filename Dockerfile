FROM alpine:3.8 as builder

ENV clang_version=5.0.1

RUN apk add --no-cache gcc libc-dev abuild binutils clang && clang --version

ENV HOME /usr/src/app
WORKDIR ${HOME}

ADD . ${HOME}/

RUN gcc locally_defined.c -o memorytest && gcc finish.c -o finish

FROM alpine:3.8

ENV HOME /usr/src/app
WORKDIR ${HOME}

COPY --chown=nobody:nogroup --from=builder ${HOME}/finish .
COPY --chown=nobody:nogroup --from=builder ${HOME}/memorytest .

USER 65534

CMD ["./memorytest"]
