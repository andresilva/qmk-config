clean-all: clean
	cd qmk_firmware; qmk clean

clean:
	rm -f qmk_firmware/layouts/community/ergodox/andresilva
	rm -f qmk_firmware/layouts/community/planck_mit/andresilva
	rm -f ergodox/ergodox
	rm -f planck/planck

link: clean
	ln -s ../../../../ergodox qmk_firmware/layouts/community/ergodox/andresilva
	ln -s ../../../../planck qmk_firmware/layouts/community/planck_mit/andresilva

build-ergodox: link
	cd qmk_firmware; qmk compile -kb ergodox_infinity -km andresilva

flash-ergodox: link
	cd qmk_firmware; qmk flash -kb ergodox_infinity -km andresilva

build-planck: link
	cd qmk_firmware; qmk compile -kb bm40hsrgb -km andresilva

flash-planck: link
	cd qmk_firmware; qmk flash -kb bm40hsrgb -km andresilva

build-all: build-ergodox build-planck

flash-all: flash-ergodox flash-planck

all: flash-all
