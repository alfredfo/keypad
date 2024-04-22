project('keypad', 'c',
	meson_version: '>=1.3.0',
	default_options: ['c_std=c17'])

src = []
incdir = []

subdir('src')
keypad = executable('keypad', src, include_directories: incdir)

prog_objcopy = find_program('objcopy')
input_bfdname = meson.get_external_property('input_bfdname')
custom_target('keypad_srecord',
	      build_by_default: true,
	      output: 'keypad.s19',
	      input: keypad,
	      command : [prog_objcopy, '-I'+input_bfdname,
			         '@INPUT@', '-Osrec', '@OUTPUT@'])
