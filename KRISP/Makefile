chisel-amethyst:
	docker run --rm -v ${shell pwd}/amethyst:/build amethyst-chisel /bin/sh -c "cd /build && sbt run"

docker-amethyst:
	 docker build -t amethyst-chisel:latest -f amethyst-chisel.Dockerfile .

.PHONY: clean
clean :
	sudo rm */*.v */*.fir */*.anno
