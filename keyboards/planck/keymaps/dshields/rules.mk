ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
COMMAND_ENABLE   = no  # Commands for debug and configuration
CONSOLE_ENABLE   = no  # Console for debug(+400)
EXTRAKEY_ENABLE  = no
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
API_SYSEX_ENABLE = no

ifeq ($(strip $(KEYBOARD)), planck/rev3)
	AUDIO_ENABLE	  = no
	BACKLIGHT_ENABLE  = yes
	RGB_MATRIX_ENABLE = no
endif
ifeq ($(strip $(KEYBOARD)), planck/rev6)
	EXTRALDFLAGS	  = -Wl,--build-id=none
	AUDIO_ENABLE	  = no
	BACKLIGHT_ENABLE  = no
	RGB_MATRIX_ENABLE = no
endif
ifeq ($(strip $(KEYBOARD)), planck/light)
	AUDIO_ENABLE	  = yes
	BACKLIGHT_ENABLE  = no
	RGB_MATRIX_ENABLE = yes
endif

