dd if=/dev/zero of=lofs.img bs=50 count=1000000
sudo losetup -f lofs.img
device=$(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)
sudo mkfs.ext4 $device
mkdir lofdisk
sudo mount $device ./lofsdisk
