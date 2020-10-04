TARGET = loopman
WEB_BUILD = ../ludum_47_omsk_gh_pages

web: web_reload web_build web_copy

web_clean:
	rm -rf cmake-build-web

web_reload:
	emcmake cmake -Bcmake-build-web -DPLATFORM=Web

web_build: web_reload
	cmake --build cmake-build-web -j 4

web_copy:
	cp cmake-build-web/index.html $(WEB_BUILD)/index.html
	cp cmake-build-web/loopman.js $(WEB_BUILD)/loopman.js
	cp cmake-build-web/loopman.wasm $(WEB_BUILD)/loopman.wasm

web_deploy:
	cd $(WEB_BUILD) && git add . && git commit -m "update" && git push origin gh-pages
