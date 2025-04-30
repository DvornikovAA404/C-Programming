set terminal png
set output 'plot.png'
set title 'Matrix Multiplication Time vs Size for different Thread Counts'
set xlabel 'Matrix Size (N)'
set ylabel 'Time (ms)'
$thread1 << EOD
100 7.29
200 53.19
300 120.93
400 307.81
500 753.12
600 1418.17
700 2198.90
800 3986.19
900 5017.58
1000 6864.09
EOD
$thread2 << EOD
100 3.33
200 26.65
300 80.78
400 252.87
500 302.99
600 544.17
700 919.70
800 1470.81
900 2155.99
1000 2854.67
EOD
$thread4 << EOD
100 3.68
200 14.02
300 46.59
400 98.61
500 181.84
600 278.23
700 547.81
800 681.03
900 1061.47
1000 1421.70
EOD
$thread8 << EOD
100 4.10
200 12.68
300 37.22
400 86.54
500 119.77
600 218.09
700 321.43
800 560.92
900 780.79
1000 1171.64
EOD
$thread16 << EOD
100 5.37
200 11.15
300 35.09
400 110.60
500 106.77
600 181.29
700 291.57
800 474.62
900 727.01
1000 1119.52
EOD
plot $thread1 with lines title '1 threads', $thread2 with lines title '2 threads', $thread4 with lines title '4 threads', $thread8 with lines title '8 threads', $thread16 with lines title '16 threads'
