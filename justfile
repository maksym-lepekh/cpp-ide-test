image-name := 'cpp-ide-test:latest'
build_dir := 'cmake-build-default'

_default: full-rebuild

# build tolchain image
build-image:
    docker build .devcontainer -f .devcontainer/Dockerfile.deb -t {{image-name}}

_run *ARGS:
    docker run --rm -it -v `pwd`:/proj -w /proj {{image-name}} {{ARGS}}

# configure project. ARGS are passed to cmake, i.e. --fresh
configure *ARGS: ( _run 'cmake --preset=default' ARGS )

# build project. ARGS are passed to cmake, i.e. --target XXX
build *ARGS: ( _run 'cmake --build --preset=default' ARGS )

# rebuild docker, clean cache and then build project
full-rebuild: build-image ( _run 'rm -r' build_dir ) configure build
