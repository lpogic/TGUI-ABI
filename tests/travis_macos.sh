set -e
mkdir build

export SFML_VERSION=2.5.0
export SFML_ROOT=$HOME/SFML_MACOS

if [[ ! -d "$SFML_ROOT/lib" ]]; then
  echo "$(tput setaf 3)Rebuilding SFML: no cache available$(tput sgr 0)"

  wget -O SFML.tar.gz https://github.com/SFML/SFML/archive/${SFML_VERSION}.tar.gz
  tar -xzf SFML.tar.gz
  cd SFML-${SFML_VERSION}
  cmake -DCMAKE_INSTALL_PREFIX=$SFML_ROOT -DCMAKE_INSTALL_FRAMEWORK_PREFIX=$SFML_ROOT/lib -DSFML_BUILD_FRAMEWORKS=TRUE .
  make -j2
  sudo make install  # sudo is needed because frameworks from dependencies (e.g. freetype) are attempting to install to /Library/Frameworks/
  cd ..
else
  echo "$(tput setaf 2)Using cached SFML directory$(tput sgr 0)"
fi

cd build
cmake -DCMAKE_INSTALL_PREFIX=$HOME/TGUI_INSTALL -DTGUI_BUILD_FRAMEWORK=TRUE -DTGUI_OPTIMIZE_SINGLE_BUILD=TRUE ..
make -j2
make install
cd ..
