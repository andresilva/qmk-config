all: flash

clean:
	rm -f qmk_firmware/layouts/community/ergodox/andresilva

link: clean
	ln -s ../../../../ergodox qmk_firmware/layouts/community/ergodox/andresilva

build: link
	qmk_firmware/bin/qmk compile -kb ergodox_infinity -km andresilva

flash: link
	qmk_firmware/bin/qmk flash -kb ergodox_infinity -km andresilva
