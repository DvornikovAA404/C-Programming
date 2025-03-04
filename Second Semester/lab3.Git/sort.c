Stud Selection(Stud Arr[N]){
    for(int i = 0; i < N; i++){
        int min = 0;
        int mind = 0;
        for(int j = i; j < N; j++){
            if(Arr[j].total > min){
                min = Arr[j].total;
                mind = j;
                Stud buffer = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = buffer;
            }
        }
    }
}