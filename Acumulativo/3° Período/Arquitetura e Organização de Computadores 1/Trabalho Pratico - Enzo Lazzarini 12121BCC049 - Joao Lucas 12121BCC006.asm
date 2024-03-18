# ALGORITMO INSERTION SORT EM ASSEMBLY!

#void insertionSort (int vet[], int n) {
#  int i, j, tmp; 
#  for (i = 1; i < n; i++) {
#    tmp = vet[i]; 
#    for (j = i-1; j >= 0 && vet[j] > tmp; j--) 
#      vet[j+1] = vet[j]; 
#    vet[j+1] = tmp; 
#  }
#}

.include "utils.asm"
.data
# Alunos: 	Enzo Lazzarini Amorim    - 12121BCC049		Jo�o Lucas Pontes Freitas    - 12121BCC006
str0:	.asciiz "Vetor n�o ordenado: "
str:	.asciiz "\nVetor ordenado: "
str1:	.asciiz " "
str2:	.asciiz "Insertion Sort em Assembly\n"
arr:	.word	384, 887, 778, 916, 794, 336, 387, 493, 650, 422, 363, 28, 691, 60, 764, 927, 541, 427, 173, 737, 212, 369, 568, 430, 783, 531, 863, 124, 68, 136, 930, 803, 23, 59, 70, 168, 394, 457, 12, 43, 230, 374, 422, 920, 785, 538, 199, 325, 316, 371, 414, 527, 92, 981, 957, 874, 863, 171, 997, 282, 306, 926, 85, 328, 337, 506, 847, 730, 314, 858, 125, 896, 583, 546, 815, 368, 435, 365, 44, 751, 88, 809, 277, 179, 789, 585, 404, 652, 755, 400, 933, 61, 677, 369, 740, 13, 227, 587, 95, 540, 796, 571, 435, 379, 468, 602, 98, 903, 318, 493, 653, 757, 302, 281, 287, 442, 866, 690, 445, 620, 441, 730, 32, 118, 98, 772, 482, 676, 710, 928, 568, 857, 498, 354, 587, 966, 307, 684, 220, 625, 529, 872, 733, 830, 504, 20, 271, 369, 709, 716, 341, 150, 797, 724, 619, 246, 847, 452, 922, 556, 380, 489, 765, 229, 842, 351, 194, 501, 35, 765, 125, 915, 988, 857, 744, 492, 228, 366, 860, 937, 433, 552, 438, 229, 276, 408, 475, 122, 859, 396, 30, 238, 236, 794, 819, 429, 144, 12, 929, 530, 777, 405, 444, 764, 614, 539, 607, 841, 905, 819, 129, 689, 370, 918, 918, 997, 325, 744, 471, 184, 491, 500, 773, 726, 645, 591, 506, 140, 955, 787, 670, 83, 543, 465, 198, 508, 356, 805, 349, 612, 623, 829, 300, 344, 747, 569, 341, 423, 312, 811, 606, 802, 662, 731, 879, 306, 321, 737, 445, 627, 523, 466, 709, 417, 283, 259, 925, 638, 63, 625, 601, 37, 453, 900, 380, 551, 469, 72, 974, 132, 882, 931, 934, 895, 661, 164, 200, 982, 900, 997, 960, 774, 814, 669, 191, 96, 927, 467, 85, 341, 91, 685, 377, 543, 937, 108, 446, 757, 180, 419, 888, 413, 349, 173, 660, 10, 337, 211, 343, 588, 207, 302, 714, 373, 322, 256, 820, 600, 722, 905, 940, 812, 941, 668, 706, 229, 128, 151, 985, 659, 921, 225, 423, 270, 397, 82, 631, 85, 293, 973, 673, 851, 626, 386, 223, 300, 641, 43, 899, 714, 299, 191, 525, 591, 210, 582, 820, 337, 733, 156, 995, 5, 380, 770, 274, 777, 851, 256, 861, 143, 580, 885, 994, 206, 622, 568, 505, 614, 962, 755, 327, 260, 945, 203, 203, 507, 785, 22, 843, 869, 529, 190, 873, 909, 959, 499, 37, 809, 754, 249, 304, 334, 134, 649, 891, 755, 568, 747, 369, 530, 501, 47, 789, 798, 250, 991, 304, 34, 364, 498, 254, 893, 687, 126, 153, 997, 976, 189, 158, 730, 437, 461, 415, 922, 461, 305, 29, 28, 51, 749, 557, 903, 795, 698, 700, 44, 40, 3, 429, 404, 501, 682, 648, 539, 160, 152, 536, 135, 340, 693, 216, 128, 505, 630, 50, 965, 286, 430, 344, 336, 178, 901, 239, 972, 950, 290, 368, 989, 293, 796, 744, 145, 830, 391, 683, 341, 542, 570, 827, 233, 262, 43, 361, 118, 24, 762, 82, 310, 191, 426, 997, 368, 678, 235, 691, 627, 525, 58, 615, 169, 206, 359, 313, 387, 101, 347, 727, 995, 917, 553, 579, 530, 947, 291, 648, 971, 52, 81, 632, 594, 858, 628, 313, 887, 215, 356, 513, 91, 413, 480, 611, 970, 190, 275, 356, 642, 621, 434, 988, 889, 339, 567, 771, 285, 857, 418, 607, 261, 850, 238, 206, 60, 218, 519, 946, 784, 874, 459, 874, 638, 290, 484, 608, 479, 758, 315, 472, 730, 101, 460, 619, 439, 26, 389, 75, 234, 158, 682, 494, 359, 271, 700, 418, 840, 570, 364, 623, 795, 174, 848, 432, 463, 683, 391, 293, 792, 58, 116, 522, 158, 575, 492, 948, 952, 232, 22, 538, 741, 55, 31, 99, 326, 82, 517, 517, 3, 232, 140, 797, 405, 339, 581, 219, 22, 971, 863, 813, 380, 978, 686, 537, 905, 177, 484, 208, 760, 858, 745, 500, 912, 128, 951, 237, 561, 819, 106, 564, 50, 245, 712, 806, 935, 292, 376, 956, 615, 590, 769, 994, 919, 806, 883, 823, 983, 718, 31, 94, 575, 127, 594, 487, 254, 544, 75, 815, 714, 180, 378, 763, 776, 89, 920, 711, 733, 295, 18, 347, 236, 138, 692, 154, 944, 574, 329, 926, 292, 711, 19, 218, 837, 964, 56, 91, 859, 131, 905, 572, 662, 634, 686, 790, 74, 605, 852, 806, 251, 869, 504, 486, 7, 196, 640, 950, 121, 968, 227, 764, 678, 597, 982, 866, 561, 37, 956, 771, 519, 212, 343, 533, 197, 380, 322, 271, 985, 173, 428, 235, 41, 284, 73, 399, 831, 64, 348, 951, 31, 574, 715, 60, 523, 48, 925, 83, 436, 233, 205, 955, 444, 899, 487, 641, 279, 160, 263, 263, 684, 42, 849, 724, 325, 273, 123, 155, 336, 822, 458, 366, 748, 172, 777, 270, 219, 702, 704, 654, 934, 908, 960, 729, 807, 798, 721, 85, 309, 335, 699, 992, 377, 899, 716, 53, 172, 190, 560, 507, 11, 17, 225, 110, 540, 1, 379, 110, 54, 82, 115, 339, 990, 427, 68, 148, 224, 788, 232, 533, 123, 282, 876, 851, 180, 591, 255, 351, 132, 814, 858, 495, 182, 82, 604, 721, 434, 983, 182, 488, 416, 297, 826, 405, 723, 893, 552, 298, 33, 135, 182, 507, 416, 58, 709, 596, 1000, 963, 298, 484, 777, 155, 978, 310, 588, 933, 383, 22, 267, 564, 861, 683, 212, 686, 87, 286, 931, 991, 584, 315, 477, 117, 821, 893, 526, 529, 840, 526, 491, 137, 361, 619, 644, 338, 929, 583, 622, 311, 956, 889, 226, 816, 571, 438, 854, 9, 723, 784, 351, 658, 98, 828, 127, 270, 72, 652, 150, 911, 529, 640, 399, 889, 611, 394, 578, 891, 977, 200, 553, 932, 88, 778, 100, 658, 567, 953, 18, 642, 736, 369, 299, 185, 196, 777, 806, 267, 429, 955, 529, 309, 594, 279, 198, 556, 673, 775, 446, 1, 326, 998, 284, 413, 128, 383, 422 

.text	

	addi 	$t4, $0, 4
	la	$s7, arr
	addi	$t3, $0, -1
	printStr(str2)
	printStr(str0)
	
	addi 	$t0, $zero, 1
F1:	slti	$t0, $s1, 1000
	beq	$t0, $zero, S1
	sll	$t2, $s1, 2
	add	$t2, $t2, $s7
	lw	$t7, 0($t2)		
	printInt($t7)
	printStr(str1)
	addi	$s1, $s1, 1
	j	F1

S1:	addi	$s1, $zero, 1 
F2:	slti	$t7, $s1, 1000
	beq	$t7, $zero, S2
	mult	$s1, $t4
	mflo	$t2
	add	$s4, $s7, $t2
	lw	$t0, 0($s4)
	addi	$s0, $s1, -1
	
F3:	slt	$t6, $t3, $s0
	mult	$s0, $t4
	mflo	$t2
	add	$s6, $s7, $t2
	lw	$t1, 0($s6)
	slt	$t5, $t0, $t1
	and	$t6, $t6, $t5 
	beq	$t6, $0, S3
	sw	$t1, 4($s6)
	addi	$s0, $s0, -1
	j F3
S3:	
	mult	$s0, $t4
	mflo	$t2
	la	$s5, arr
	add	$s5, $s5, $t2
	sw	$t0, 4($s5)
	addi	$s1, $s1, 1
	j	F2
S2:	
	printStr(str)
	la	$s7, arr		
	add	$s1, $zero, $zero
F4:	slti	$t0, $s1, 1000
	beq	$t0, $zero, S4
	sll	$t2, $s1, 2
	add	$t2, $t2, $s7
	lw	$t3, 0($t2)		
	printInt($t3)
	printStr(str1)
	addi	$s1, $s1, 1
	j	F4
S4:
	return0
	
