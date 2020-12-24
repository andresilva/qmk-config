clean-all: clean
	qmk_firmware/bin/qmk clean

clean:
	rm -f qmk_firmware/layouts/community/ergodox/andresilva
	rm -f qmk_firmware/layouts/community/planck_mit/andresilva
	rm -f ergodox/ergodox
	rm -f planck/planck

link: clean
	ln -s ../../../../ergodox qmk_firmware/layouts/community/ergodox/andresilva
	ln -s ../../../../planck qmk_firmware/layouts/community/planck_mit/andresilva

build-ergodox: link
	qmk_firmware/bin/qmk compile -kb ergodox_infinity -km andresilva

flash-ergodox: link
	qmk_firmware/bin/qmk flash -kb ergodox_infinity -km andresilva

build-planck: link
	qmk_firmware/bin/qmk compile -kb bm40hsrgb -km andresilva

flash-planck: link
	qmk_firmware/bin/qmk flash -kb bm40hsrgb -km andresilva

build-all: build-ergodox build-planck

flash-all: flash-ergodox flash-planck

all: flash-all
