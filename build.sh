# wheatfox's build script for Loongson 3A5000 hvisor's linux zone
# target is vmlinux ELF file for booting the zone
# 2024.3.12

ARCH=loongarch
CROSS_COMPILE=loongarch64-unknown-linux-gnu-
ARGS="ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE"
NUM_JOBS=16
TARGET_DEFCONFIG=loongson3_defconfig

if [ "$1" = "help" ] || [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "" ]; then
    echo "  Commands:"
    echo "    help                - Show this help"
    echo "    def                 - Run defconfig"
    echo "    clean               - Clean the build"
    echo "    menuconfig          - Run menuconfig"
    echo "    save                - Save defconfig"
    echo "    kernel              - Build kernel"
    echo "    copydtb             - Copy dtb to arch/loongarch/boot/loongson3_ls7a.dtb"
    echo "    copy                - Copy kernel to hvisor(loongarch64)'s images folder"
    exit 0
fi

if [ "$1" = "def" ]; then
    echo "Running defconfig"
    make $ARGS $TARGET_DEFCONFIG
    exit 0
fi

if [ "$1" = "clean" ]; then
    echo "Cleaning the build"
    make $ARGS clean
    exit 0
fi

if [ "$1" = "menuconfig" ]; then
    echo "Running menuconfig"
    make $ARGS menuconfig
    exit 0
fi

if [ "$1" = "save" ]; then
    echo "Running save defconfig, copying .config to arch/$ARCH/configs/$TARGET_DEFCONFIG"
    cp .config arch/$ARCH/configs/$TARGET_DEFCONFIG
    exit 0
fi

if [ "$1" = "kernel" ]; then
    echo "Building kernel"
    make $ARGS -j$NUM_JOBS
    # objdump the asm of vmlinux, dump all sections' data
    loongarch64-unknown-linux-gnu-objdump -D vmlinux >vmlinux.asm
    # readelf
    loongarch64-unknown-linux-gnu-readelf -a vmlinux >vmlinux.readelf.txt
    exit 0
fi

# HVISOR_SRC=/home/wheatfox/Documents/Code/loongvisor
# find HVISOR_SRC in the environment variables if not set warning
if [ -z "$HVISOR_SRC" ]; then
    echo "HVISOR_SRC is not set, please set it to the path of the hvisor source code"
    echo "you can add it in your .bashrc or .zshrc file or temporarily set it like this:"
    echo "--"
    echo "export HVISOR_SRC=/home/wheatfox/Documents/Code/loongvisor"
    echo "--"
    exit 1
fi
HVISOR_SRC=$(realpath $HVISOR_SRC)
echo "HVISOR_SRC is set to $HVISOR_SRC"

if [ "$1" = "copy" ]; then
    echo "Copying kernel to hvisor(loongarch64)'s images folder: $HVISOR_SRC/images/vmlinux"
    cp vmlinux $HVISOR_SRC/images/vmlinux
    echo "Finished copying kernel"
    exit 0
fi

HVISOR_DTB=$HVISOR_SRC/dts/loongson3_ls7a.dtb
if [ "$1" = "copydtb" ]; then
    echo "Copying dtb to arch/loongarch/boot/loongson3_ls7a.dtb from $HVISOR_DTB"
    cp $HVISOR_DTB arch/loongarch/boot/loongson3_ls7a.dtb
    echo "Finished copying dtb"
    exit 0
fi
