#!/usr/bin/perl

my @data;

open(my $lines, "<","lines.tmp");
while(defined ($line = <$lines>)){
    chop $line;
    $count =()= $line =~ / /g;
    $line =~ s/ /","/g;
    
    push @data, ("{$count,\"" . $line . "\"},\n");
}
close($file);

open(my $data, ">","data.tmp");
for my $line (@data){
    print $data $line;
}


