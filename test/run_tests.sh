#!/usr/bin/sh

die()
{
	echo $*
	exit 1
}

main()
{
	for x in $(find -maxdepth 1 -regex './test[0-9]+'); do
		$x >/dev/null || die "error: '$(basename $x)' => $?"
	done
}

main
