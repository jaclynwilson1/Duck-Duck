FROM gcc:9

RUN brew install cmake

COPY . /usr

RUN rm -rf build; mkdir build && cd build; cmake ..; make

ENTRYPOINT [./DuckDuck]