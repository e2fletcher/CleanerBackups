# Maintainer: Ender Fletcher <e2fletcher@gmail.com>
pkgname=CleanerBackups
pkgver=0.1
pkgrel=1
pkgdesc="Limpiador de archivos para hacer copias de seguridad en Windows"
arch=('i686')
url="https://www.facebook.com/e2fletcher"
license=('GPL3')

package() {
    cmake
}

pkgver() {
      cd "$srcdir/$pkgname"
        # Use the tag of the last commit
          printf "0.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
      }

package() {
    cd "$srcdir/$pkgname"
    install -d -m 755 "$pkgdir"/usr/share/icons/Flattr
    rm -rf {.git,.gitignore,CONTRIBUTORS,COPYING,CREDITS,LICENSE.txt,README.md}
    cp -r . "$pkgdir"/usr/share/icons/Flattr/
:wq
}

