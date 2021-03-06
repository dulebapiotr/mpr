#!/bin/bash -l
#SBATCH --nodes 1
#SBATCH --ntasks 12
#SBATCH --time=2:00:00
#SBATCH --partition=plgrid
#SBATCH --account=plgmpr21zeus
#SBATCH --constraint="intel" 

module add plgrid/tools/openmpi

make build

chmod 777 *

make strong n=20000000000
make strong n=550000000
make strong n=15000000

make weak n=20000000000
make weak n=550000000
make weak n=1500000