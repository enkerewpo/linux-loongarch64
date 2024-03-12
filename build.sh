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
    exit 0
fi
