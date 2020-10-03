TARGET = loopman

web: web_reload web_build

web_clean:
	rm -rf cmake-build-web

web_reload:
	emcmake cmake -Bcmake-build-web -DPLATFORM=Web

web_build: web_reload
	cmake --build cmake-build-web -j 4
