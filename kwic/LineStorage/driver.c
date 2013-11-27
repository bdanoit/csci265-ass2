/********** LineStorage module---test driver **********/

#include <stdio.h>
#include "kwic.h"
#include "LineStorage.h"

#define NUMLINES 348
#define MAXWORDS 11

struct {
	int numWords;
	char* wordList[MAXWORDS];
} lineList[NUMLINES] = {
	/*{5,"The","Cat","in","the","Hat"},
	{4,"The","C","Programming","Language"},
	{0},
	{1,"xxx"},
	{3,"","x","01234567890123456789012345678901234567890123456789"}*/{7,"Lorem","ipsum","dolor","sit","amet,","consectetur","adipiscing","elit."},
{6,"Cras","eu","justo","vitae","ligula","tincidunt","porttitor."},
{6,"Fusce","non","elit","eu","nibh","laoreet","lacinia."},
{9,"Curabitur","lacinia","quam","eu","sapien","lobortis,","porttitor","interdum","tellus","commodo."},
{5,"Sed","dictum","orci","fringilla","gravida","posuere."},
{6,"Vestibulum","vitae","velit","sed","erat","euismod","interdum."},
{5,"Curabitur","imperdiet","ipsum","eu","pellentesque","sodales."},
{9,"Etiam","tincidunt","eros","at","dolor","ultricies,","quis","pharetra","felis","cursus."},
{9,"Donec","at","mauris","condimentum","felis","ullamcorper","tristique","ut","eu","ligula."},
{5,"Aenean","cursus","diam","eu","bibendum","lacinia."},
{9,"Maecenas","a","augue","ut","nibh","mattis","pharetra","quis","quis","enim."},
{9,"Sed","vestibulum","ipsum","in","purus","pharetra,","ut","aliquet","odio","aliquam."},
{9,"Praesent","ac","ante","vel","erat","hendrerit","pharetra","id","at","tellus."},
{8,"Fusce","ac","dolor","mattis,","condimentum","elit","volutpat,","pulvinar","metus."},
{6,"Sed","semper","eros","sit","amet","iaculis","lobortis."},
{8,"Suspendisse","et","velit","convallis,","laoreet","ipsum","vel,","ultrices","sapien."},
{10,"Vestibulum","in","arcu","vitae","ligula","sollicitudin","posuere","sit","amet","et","erat."},
{9,"Cras","faucibus","eros","vel","ligula","imperdiet,","a","imperdiet","ipsum","aliquet."},
{10,"Aenean","mollis","elit","vel","diam","egestas,","sit","amet","scelerisque","urna","mattis."},
{9,"Fusce","sodales","nunc","sed","neque","viverra,","eu","tempor","diam","tincidunt."},
{7,"Aenean","nec","tortor","sit","amet","quam","aliquet","ullamcorper."},
{9,"Integer","tempor","enim","eu","nibh","pharetra,","nec","sagittis","nisl","mollis."},
{6,"Morbi","elementum","lectus","sed","ipsum","dignissim","luctus."},
{10,"Praesent","faucibus","velit","sed","erat","bibendum,","sit","amet","cursus","eros","venenatis."},
{6,"Vestibulum","fermentum","nulla","id","turpis","ultrices","lacinia."},
{6,"Mauris","quis","ligula","ut","metus","ornare","lacinia."},
{6,"Morbi","pharetra","magna","sed","ipsum","blandit","gravida."},
{6,"Sed","quis","lectus","vitae","arcu","tempus","bibendum."},
{8,"Morbi","eget","quam","posuere,","placerat","purus","vel,","tincidunt","elit."},
{9,"Fusce","tristique","mauris","ut","eros","commodo,","at","condimentum","eros","tristique."},
{9,"Aenean","pharetra","massa","eu","velit","tempus","sagittis","sed","at","nunc."},
{9,"Nam","id","nisl","vel","erat","placerat","faucibus","vitae","at","nibh."},
{6,"Sed","aliquam","nunc","a","orci","eleifend","tincidunt."},
{6,"Etiam","hendrerit","elit","nec","risus","blandit","viverra."},
{5,"Morbi","congue","ligula","sed","consequat","interdum."},
{5,"Maecenas","sodales","nisl","vel","tempus","vulputate."},
{6,"Sed","vel","nibh","ac","libero","sollicitudin","vestibulum."},
{5,"Quisque","luctus","nisi","non","ultricies","malesuada."},
{5,"Aenean","tempor","nibh","porttitor","dictum","facilisis."},
{9,"Ut","euismod","lacus","eu","lorem","imperdiet,","vitae","mollis","magna","ultricies."},
{9,"Nam","iaculis","neque","vel","est","suscipit","porta","et","vel","lorem."},
{8,"Donec","vel","nibh","varius,","posuere","ligula","ut,","adipiscing","lacus."},
{6,"Cras","a","est","non","arcu","adipiscing","eleifend."},
{6,"Pellentesque","et","nulla","non","velit","dapibus","fermentum."},
{9,"Aenean","suscipit","libero","quis","nunc","facilisis,","sed","facilisis","massa","varius."},
{9,"Quisque","sed","tellus","ut","nibh","imperdiet","egestas","sed","ac","eros."},
{9,"Duis","interdum","nunc","eget","metus","hendrerit,","et","molestie","neque","malesuada."},
{9,"Phasellus","faucibus","odio","at","lectus","porta","tempus","ut","ut","sem."},
{5,"Proin","euismod","libero","sed","faucibus","suscipit."},
{10,"Mauris","non","massa","in","mi","rutrum","posuere","sit","amet","a","purus."},
{6,"Proin","vehicula","tortor","et","risus","dignissim","sodales."},
{8,"Suspendisse","eget","erat","convallis,","hendrerit","justo","tempus,","facilisis","orci."},
{10,"Nam","sit","amet","sem","vel","est","viverra","dignissim","in","eu","nulla."},
{9,"Etiam","ac","magna","nec","mi","tristique","ullamcorper","in","nec","lorem."},
{6,"Curabitur","rhoncus","nisl","in","mi","placerat","laoreet."},
{6,"Cras","venenatis","tellus","at","odio","porta","viverra."},
{5,"Sed","dictum","magna","sed","viverra","sodales."},
{8,"Sed","non","nunc","varius,","cursus","nisi","vel,","fringilla","leo."},
{9,"Quisque","scelerisque","mauris","consectetur","ipsum","mollis,","in","iaculis","odio","iaculis."},
{6,"Sed","interdum","nibh","vestibulum","nisl","dignissim","tincidunt."},
{10,"Vivamus","sit","amet","urna","a","tellus","vestibulum","condimentum","ut","id","nisi."},
{6,"Quisque","dictum","augue","et","lorem","tempor","tincidunt."},
{10,"Nullam","ultricies","erat","et","mi","aliquet","consequat","sit","amet","at","justo."},
{9,"Nulla","eu","lacus","dapibus","quam","tincidunt","volutpat","vitae","ut","turpis."},
{9,"Suspendisse","quis","eros","in","felis","rutrum","consectetur","nec","ac","nibh."},
{8,"Curabitur","nec","purus","pharetra,","feugiat","libero","nec,","varius","lacus."},
{8,"Pellentesque","et","tortor","pretium,","sagittis","mi","non,","bibendum","leo."},
{8,"Maecenas","et","neque","semper,","rhoncus","velit","at,","congue","dui."},
{8,"Phasellus","sed","turpis","fermentum,","lacinia","leo","quis,","sollicitudin","libero."},
{6,"Maecenas","pellentesque","velit","vitae","arcu","porttitor","scelerisque."},
{9,"Fusce","sit","amet","urna","lobortis,","sodales","metus","a,","mollis","felis."},
{9,"Phasellus","sollicitudin","metus","quis","erat","ornare,","non","fringilla","tortor","sollicitudin."},
{6,"Fusce","lobortis","tellus","vitae","quam","bibendum","porttitor."},
{8,"Integer","ac","urna","ullamcorper,","mattis","eros","lacinia,","viverra","nulla."},
{9,"Vestibulum","sit","amet","mauris","lacinia,","porttitor","justo","consectetur,","pellentesque","nunc."},
{5,"Proin","tincidunt","neque","mattis","euismod","dapibus."},
{5,"Aenean","sagittis","massa","quis","convallis","feugiat."},
{5,"Ut","eleifend","arcu","eu","iaculis","sollicitudin."},
{9,"Aenean","auctor","turpis","eget","sapien","consequat,","sed","cursus","metus","pulvinar."},
{9,"Mauris","quis","risus","consequat,","porta","lacus","sit","amet,","euismod","dui."},
{9,"Integer","et","justo","a","ipsum","elementum","bibendum","a","et","purus."},
{5,"Etiam","aliquam","sapien","laoreet","tincidunt","feugiat."},
{9,"Fusce","vestibulum","sem","quis","turpis","convallis,","nec","sollicitudin","eros","venenatis."},
{7,"Nunc","sit","amet","ante","in","dolor","congue","tempus."},
{5,"In","euismod","augue","in","consequat","lacinia."},
{9,"Vivamus","gravida","nulla","eget","velit","condimentum,","vel","dignissim","nulla","condimentum."},
{5,"Curabitur","eleifend","massa","at","malesuada","porta."},
{8,"Morbi","eget","diam","feugiat,","posuere","metus","at,","adipiscing","purus."},
{5,"Sed","vehicula","odio","vitae","adipiscing","luctus."},
{9,"Praesent","in","eros","ut","libero","varius","condimentum","sed","quis","enim."},
{9,"Fusce","a","mi","a","turpis","fermentum","vestibulum","eget","sed","est."},
{9,"Donec","nec","nisl","at","magna","tempor","laoreet","id","vitae","odio."},
{6,"Quisque","tincidunt","diam","sed","enim","fringilla","pretium."},
{7,"Pellentesque","vestibulum","sapien","sit","amet","tellus","hendrerit","rhoncus."},
{6,"Sed","aliquam","libero","nec","nisi","hendrerit","posuere."},
{6,"Donec","ullamcorper","justo","eu","magna","porta","sollicitudin."},
{6,"Duis","et","mi","quis","felis","sagittis","cursus."},
{8,"Duis","et","arcu","aliquam,","viverra","justo","sed,","condimentum","dolor."},
{7,"Quisque","et","lorem","sit","amet","ipsum","consequat","laoreet."},
{6,"Nunc","in","diam","et","elit","congue","volutpat."},
{9,"Aenean","eu","metus","sed","mi","dictum","ultricies","ut","et","dui."},
{6,"Nulla","convallis","nisi","et","sem","faucibus","lobortis."},
{6,"Maecenas","hendrerit","arcu","vitae","lorem","eleifend","porta."},
{5,"Vestibulum","imperdiet","lorem","vel","lobortis","consectetur."},
{5,"Duis","tristique","ligula","eget","dignissim","laoreet."},
{6,"Cras","nec","odio","ut","sem","fringilla","aliquet."},
{6,"Fusce","interdum","eros","sit","amet","congue","tempor."},
{5,"Curabitur","facilisis","neque","quis","iaculis","tincidunt."},
{9,"Nunc","lacinia","purus","a","orci","cursus,","ac","porta","purus","venenatis."},
{8,"Sed","ac","dolor","pretium,","congue","elit","non,","congue","tortor."},
{8,"Nunc","ornare","ante","viverra,","laoreet","mauris","eu,","elementum","magna."},
{8,"Cras","non","tortor","pharetra,","tempus","ligula","consectetur,","laoreet","nunc."},
{6,"Mauris","non","nisi","id","magna","porttitor","condimentum."},
{5,"Ut","dapibus","orci","vitae","aliquet","eleifend."},
{5,"Suspendisse","gravida","urna","semper","blandit","consequat."},
{6,"Praesent","ullamcorper","sem","eget","magna","fringilla","pellentesque."},
{9,"Nulla","consectetur","urna","eu","dui","scelerisque,","et","ultricies","erat","pellentesque."},
{6,"Pellentesque","commodo","magna","at","metus","pulvinar","consectetur."},
{10,"Suspendisse","non","ipsum","auctor","massa","convallis","interdum","sit","amet","ac","diam."},
{6,"Vivamus","placerat","mauris","vitae","sapien","condimentum","interdum."},
{9,"Donec","at","erat","at","velit","feugiat","eleifend","a","nec","justo."},
{9,"Maecenas","id","felis","non","elit","cursus","interdum","non","nec","quam."},
{8,"Nam","ac","eros","aliquam,","cursus","lacus","vitae,","viverra","tortor."},
{8,"Donec","non","quam","gravida,","sodales","felis","et,","venenatis","justo."},
{6,"Pellentesque","non","eros","vel","felis","tincidunt","tempus."},
{8,"Proin","et","eros","tempor,","varius","nulla","id,","rutrum","lectus."},
{9,"In","iaculis","est","vel","tortor","dapibus,","non","feugiat","felis","vestibulum."},
{5,"Suspendisse","faucibus","libero","id","molestie","vulputate."},
{5,"Aliquam","sollicitudin","urna","et","aliquam","varius."},
{6,"Donec","aliquet","purus","et","turpis","lobortis","gravida."},
{5,"Nam","molestie","libero","eleifend","dictum","gravida."},
{10,"Phasellus","et","ligula","quis","arcu","scelerisque","sodales","sit","amet","in","ante."},
{6,"Mauris","non","eros","accumsan","erat","molestie","accumsan."},
{9,"Nulla","id","tortor","eget","massa","interdum","fringilla","et","id","tortor."},
{8,"Cras","in","turpis","blandit,","auctor","magna","ut,","imperdiet","arcu."},
{5,"Phasellus","auctor","ipsum","vitae","venenatis","vehicula."},
{8,"Donec","ut","justo","mattis,","ornare","nisi","vel,","elementum","felis."},
{6,"Quisque","blandit","mi","nec","arcu","iaculis","euismod."},
{5,"Maecenas","vestibulum","leo","eget","ullamcorper","volutpat."},
{9,"Etiam","at","lectus","vel","neque","semper","pharetra","ut","at","mi."},
{8,"Donec","quis","massa","tincidunt,","varius","ipsum","quis,","iaculis","sapien."},
{10,"Sed","bibendum","lectus","sit","amet","tellus","vehicula,","eget","ornare","nunc","auctor."},
{5,"Nulla","pellentesque","sapien","in","mollis","condimentum."},
{5,"Aenean","venenatis","leo","in","mollis","fringilla."},
{9,"Vestibulum","ornare","ante","eu","purus","condimentum,","bibendum","feugiat","metus","pretium."},
{9,"Quisque","vestibulum","lacus","eget","erat","rhoncus,","id","tempus","sapien","consequat."},
{5,"Etiam","malesuada","purus","eget","facilisis","accumsan."},
{6,"Praesent","hendrerit","arcu","eu","metus","consectetur","ullamcorper."},
{9,"In","vel","nunc","a","quam","bibendum","scelerisque","convallis","eget","odio."},
{7,"Nulla","ultricies","leo","sit","amet","nibh","blandit","sodales."},
{6,"Nulla","ac","ante","non","lacus","lacinia","suscipit."},
{10,"In","tincidunt","tortor","sit","amet","risus","porttitor,","at","pulvinar","libero","commodo."},
{6,"Maecenas","tincidunt","justo","sit","amet","vehicula","dignissim."},
{6,"Vestibulum","eget","lectus","vel","lorem","adipiscing","commodo."},
{9,"Praesent","egestas","metus","ut","felis","semper,","et","aliquet","purus","hendrerit."},
{9,"Praesent","pellentesque","nunc","sed","lorem","volutpat,","in","viverra","nulla","fermentum."},
{9,"Phasellus","venenatis","purus","et","odio","pretium,","nec","posuere","velit","consequat."},
{6,"Suspendisse","fermentum","mauris","ut","nibh","placerat","laoreet."},
{6,"Curabitur","vel","nisi","id","libero","mattis","euismod."},
{7,"Maecenas","et","nulla","sit","amet","nibh","ultricies","semper."},
{6,"Mauris","ornare","erat","id","massa","tincidunt","bibendum."},
{8,"Phasellus","semper","ligula","imperdiet,","pellentesque","enim","vitae,","molestie","magna."},
{6,"Vivamus","lobortis","dui","id","ligula","mollis","iaculis."},
{9,"Ut","mattis","libero","quis","turpis","hendrerit,","vel","vulputate","leo","lacinia."},
{6,"Pellentesque","fermentum","justo","ac","odio","tempus","pharetra."},
{8,"Pellentesque","id","magna","sagittis,","cursus","lacus","non,","lobortis","erat."},
{7,"Mauris","sit","amet","lacus","eu","nibh","adipiscing","elementum."},
{6,"Nullam","quis","sem","sed","tortor","posuere","porttitor."},
{10,"Etiam","rutrum","nulla","vel","magna","facilisis","adipiscing","ut","sit","amet","mi."},
{9,"Vestibulum","tempor","velit","vel","mauris","posuere,","et","iaculis","urna","bibendum."},
{5,"Sed","vulputate","lacus","ut","luctus","fringilla."},
{9,"Nunc","gravida","erat","eget","odio","vulputate,","vitae","sollicitudin","mauris","cursus."},
{9,"Quisque","iaculis","velit","a","nisl","porta,","sed","volutpat","mi","commodo."},
{6,"Fusce","ac","arcu","ut","justo","gravida","feugiat."},
{5,"Morbi","suscipit","tellus","at","dictum","mattis."},
{5,"Nullam","volutpat","lacus","non","vestibulum","lacinia."},
{5,"Integer","ullamcorper","magna","sed","bibendum","egestas."},
{8,"Nulla","nec","justo","dapibus,","vehicula","sapien","ac,","consequat","tellus."},
{10,"Curabitur","varius","tortor","a","nisl","convallis,","sit","amet","dictum","justo","adipiscing."},
{9,"Curabitur","sed","elit","at","ligula","vulputate","feugiat","faucibus","nec","magna."},
{6,"Nunc","auctor","leo","at","enim","ullamcorper","suscipit."},
{8,"Curabitur","at","turpis","hendrerit,","adipiscing","sapien","non,","ullamcorper","velit."},
{5,"Pellentesque","condimentum","sem","eu","tincidunt","rhoncus."},
{6,"Pellentesque","pulvinar","lorem","sed","massa","aliquam","varius."},
{6,"In","vestibulum","enim","vitae","lorem","egestas","convallis."},
{6,"Nullam","feugiat","libero","at","felis","molestie","tincidunt."},
{5,"Proin","rutrum","tortor","vel","condimentum","volutpat."},
{8,"Phasellus","eu","mauris","euismod,","consequat","neque","nec,","gravida","mi."},
{9,"Pellentesque","condimentum","ante","iaculis","nisi","rhoncus,","ut","ultricies","tortor","vestibulum."},
{6,"Mauris","et","dolor","id","nibh","volutpat","facilisis."},
{5,"In","vulputate","risus","sed","fringilla","semper."},
{5,"Donec","aliquet","enim","ac","rutrum","condimentum."},
{5,"Vivamus","adipiscing","elit","vitae","tincidunt","dapibus."},
{9,"Integer","porta","ante","id","libero","blandit","pellentesque","vitae","id","neque."},
{9,"Pellentesque","at","purus","id","lacus","feugiat","dictum","ac","eu","sem."},
{6,"Sed","mollis","leo","et","nisi","dignissim","euismod."},
{6,"Ut","et","magna","eu","elit","egestas","aliquam."},
{5,"In","iaculis","nisl","ut","consectetur","tincidunt."},
{5,"Integer","mattis","nunc","sed","fringilla","posuere."},
{8,"Integer","sed","nisl","malesuada,","sodales","ante","id,","auctor","lectus."},
{8,"Suspendisse","id","est","ullamcorper,","vestibulum","sapien","sed,","ultricies","tortor."},
{9,"Morbi","sollicitudin","felis","at","libero","eleifend,","nec","pretium","arcu","viverra."},
{5,"Aenean","vestibulum","tellus","eu","elementum","commodo."},
{6,"Nunc","ultrices","orci","a","sem","condimentum","pharetra."},
{6,"Mauris","adipiscing","augue","condimentum","nulla","convallis","pellentesque."},
{9,"Etiam","interdum","erat","nec","ligula","eleifend,","nec","auctor","est","tristique."},
{5,"Proin","suscipit","mi","in","ornare","scelerisque."},
{8,"Nam","sed","magna","varius,","pharetra","neque","vel,","eleifend","ligula."},
{6,"Nullam","dignissim","tellus","ut","nibh","consequat","tristique."},
{9,"Donec","et","tellus","nec","urna","dignissim","laoreet","vel","sed","felis."},
{6,"Cras","cursus","ligula","ultricies","felis","posuere","malesuada."},
{6,"Vivamus","condimentum","sapien","et","est","mollis","gravida."},
{6,"Proin","ut","purus","id","ante","aliquet","viverra."},
{9,"Mauris","pharetra","felis","eu","nisl","pulvinar,","ut","consectetur","odio","fringilla."},
{6,"Quisque","scelerisque","diam","ac","neque","mattis","tincidunt."},
{5,"Morbi","iaculis","mi","at","eleifend","vehicula."},
{9,"Cras","viverra","justo","et","sapien","fringilla,","quis","mattis","mauris","varius."},
{9,"Morbi","bibendum","nunc","vitae","lectus","accumsan,","a","volutpat","nibh","congue."},
{5,"Vestibulum","sodales","nulla","consequat","feugiat","eleifend."},
{9,"Praesent","at","ligula","mattis","eros","fringilla","rhoncus","non","vel","libero."},
{10,"Integer","bibendum","lacus","sit","amet","magna","egestas,","tempus","viverra","enim","egestas."},
{9,"Vivamus","id","sem","lobortis","arcu","sagittis","imperdiet","eget","at","massa."},
{9,"Vestibulum","volutpat","orci","at","est","ornare,","sed","venenatis","felis","tincidunt."},
{6,"Cras","blandit","justo","id","neque","tincidunt","fermentum."},
{9,"Curabitur","id","enim","porttitor,","adipiscing","lectus","sit","amet,","hendrerit","lorem."},
{6,"Suspendisse","a","lacus","sed","ante","iaculis","cursus."},
{6,"Phasellus","tempus","lacus","a","magna","porta","sagittis."},
{7,"Proin","eu","nisl","sit","amet","quam","fringilla","luctus."},
{10,"Curabitur","eu","orci","a","mi","aliquam","aliquet","eu","sit","amet","nunc."},
{9,"Vestibulum","adipiscing","purus","eget","magna","porta","sagittis","non","quis","felis."},
{10,"Morbi","sit","amet","nisi","a","metus","suscipit","porttitor","nec","sed","eros."},
{6,"Sed","at","libero","quis","nulla","gravida","molestie."},
{9,"Nam","sed","massa","id","sapien","viverra","bibendum","vitae","ut","justo."},
{9,"Nulla","tempus","ante","sed","dui","egestas,","a","suscipit","diam","elementum."},
{9,"Morbi","id","massa","at","eros","iaculis","eleifend","quis","ornare","felis."},
{8,"Fusce","non","ligula","tristique,","lacinia","ante","et,","sodales","metus."},
{9,"Nunc","cursus","eros","quis","felis","venenatis,","in","porttitor","nibh","porttitor."},
{5,"Nam","pretium","erat","in","pharetra","varius."},
{9,"Nam","ullamcorper","odio","ac","augue","varius,","ac","adipiscing","eros","malesuada."},
{6,"Vestibulum","faucibus","mauris","volutpat","metus","volutpat","hendrerit."},
{5,"Nam","adipiscing","dolor","eleifend","lacinia","vestibulum."},
{9,"Nam","eu","sapien","ut","ipsum","porta","pulvinar","in","quis","libero."},
{5,"Phasellus","rhoncus","nibh","in","venenatis","tristique."},
{9,"Vivamus","auctor","dolor","et","ante","sodales,","id","accumsan","turpis","gravida."},
{9,"Cras","sed","purus","a","orci","interdum","elementum","nec","et","erat."},
{9,"Duis","sit","amet","tortor","tempus,","commodo","felis","ut,","ullamcorper","elit."},
{8,"Mauris","et","erat","sollicitudin,","consectetur","est","id,","luctus","diam."},
{9,"Ut","commodo","ligula","volutpat","libero","laoreet,","quis","ornare","augue","iaculis."},
{8,"Quisque","consectetur","elit","volutpat,","laoreet","nulla","eget,","consequat","odio."},
{5,"Ut","gravida","tortor","et","placerat","euismod."},
{6,"Suspendisse","non","libero","quis","neque","blandit","gravida."},
{5,"Donec","vulputate","risus","et","luctus","vulputate."},
{9,"Phasellus","dapibus","justo","at","nisi","tristique,","non","venenatis","enim","volutpat."},
{5,"Nunc","pretium","justo","nec","laoreet","euismod."},
{6,"Morbi","ac","erat","mattis","mi","egestas","ultricies."},
{6,"Cras","vel","nisi","eget","sapien","consectetur","eleifend."},
{5,"Curabitur","ullamcorper","elit","et","sollicitudin","condimentum."},
{6,"Mauris","vel","velit","eget","est","interdum","dictum."},
{9,"Aenean","nec","mauris","at","nisl","pellentesque","tempus","et","id","neque."},
{6,"Maecenas","dapibus","lectus","ac","diam","pharetra","faucibus."},
{6,"Ut","sed","odio","quis","nunc","dapibus","lacinia."},
{9,"Suspendisse","scelerisque","tortor","vel","magna","semper","porttitor","at","ac","mi."},
{10,"Integer","sed","urna","at","elit","faucibus","adipiscing","sit","amet","eget","justo."},
{9,"Morbi","a","eros","eget","metus","suscipit","dapibus","eget","non","lectus."},
{9,"Aenean","non","dolor","ut","mauris","accumsan","varius","eu","ut","leo."},
{6,"Aenean","sollicitudin","eros","id","ligula","egestas","placerat."},
{9,"Nunc","et","odio","non","ligula","vehicula","commodo","in","in","neque."},
{8,"Duis","fermentum","libero","posuere,","commodo","quam","eget,","convallis","turpis."},
{9,"Mauris","sed","ante","in","nibh","vestibulum","aliquet","id","fringilla","sapien."},
{5,"Pellentesque","dapibus","justo","ut","luctus","imperdiet."},
{9,"Duis","convallis","massa","sed","felis","pharetra","posuere","sed","nec","lectus."},
{8,"Donec","ac","augue","aliquet,","volutpat","nisi","vel,","scelerisque","orci."},
{6,"Proin","in","est","vitae","lorem","fermentum","vestibulum."},
{9,"Nullam","id","magna","vel","nibh","venenatis","sagittis","nec","sed","est."},
{6,"Donec","laoreet","felis","et","justo","gravida","semper."},
{9,"Vestibulum","convallis","lorem","sagittis","tortor","rhoncus,","eu","molestie","ligula","malesuada."},
{9,"Integer","accumsan","elit","ac","dolor","ultricies,","eget","gravida","leo","porta."},
{6,"Pellentesque","in","purus","a","erat","placerat","consequat."},
{6,"Donec","et","nunc","vitae","lacus","molestie","eleifend."},
{6,"In","id","tellus","sed","nulla","ultricies","porta."},
{8,"Phasellus","vitae","velit","auctor,","cursus","tellus","id,","lobortis","magna."},
{8,"Nunc","ut","nunc","aliquam,","pulvinar","mi","a,","vehicula","nulla."},
{5,"Aenean","cursus","tortor","eget","tempor","interdum."},
{6,"Suspendisse","malesuada","quam","ut","lectus","posuere","elementum."},
{6,"Duis","ultrices","arcu","vitae","libero","vehicula","ornare."},
{7,"Curabitur","eu","risus","sit","amet","mi","lobortis","accumsan."},
{8,"Morbi","eu","mauris","iaculis,","ornare","diam","non,","aliquet","nisi."},
{9,"Cras","scelerisque","lacus","eu","nunc","eleifend,","eu","ullamcorper","urna","facilisis."},
{6,"Nulla","tincidunt","dolor","quis","eros","facilisis","auctor."},
{9,"Nunc","vitae","dui","non","ligula","vehicula","pulvinar","id","non","risus."},
{8,"Duis","ac","tellus","eleifend,","ullamcorper","libero","eget,","scelerisque","sapien."},
{9,"Etiam","volutpat","nunc","a","dui","hendrerit,","vel","viverra","erat","venenatis."},
{8,"Mauris","nec","nulla","blandit,","posuere","dolor","nec,","consequat","nisi."},
{10,"Pellentesque","sed","augue","in","enim","tincidunt","mollis","ac","sit","amet","enim."},
{6,"Proin","bibendum","lorem","nec","erat","iaculis","tempus."},
{9,"Nam","accumsan","orci","rutrum","mauris","fermentum,","in","pretium","lorem","dictum."},
{9,"Nulla","consectetur","augue","vel","dolor","iaculis,","a","tempor","orci","tincidunt."},
{5,"Curabitur","commodo","felis","id","scelerisque","tempor."},
{8,"Aliquam","ut","sapien","scelerisque,","sagittis","diam","eu,","sollicitudin","felis."},
{9,"Donec","ultrices","mi","id","velit","pellentesque","bibendum","non","vitae","mauris."},
{9,"Morbi","at","ipsum","sed","arcu","molestie","vehicula","nec","at","libero."},
{9,"Maecenas","id","justo","vel","velit","posuere","hendrerit","sollicitudin","a","erat."},
{9,"Pellentesque","volutpat","nisi","in","orci","posuere,","varius","scelerisque","justo","posuere."},
{6,"Integer","auctor","libero","ullamcorper","metus","sagittis","faucibus."},
{6,"Aliquam","in","justo","at","erat","gravida","molestie."},
{5,"Vivamus","luctus","sem","sed","vehicula","consectetur."},
{9,"Donec","ut","neque","vel","purus","fermentum","scelerisque","nec","vitae","turpis."},
{10,"Fusce","quis","dui","ac","sapien","rhoncus","accumsan","sit","amet","quis","enim."},
{9,"Praesent","ultrices","ipsum","quis","ligula","congue,","tincidunt","iaculis","leo","elementum."},
{6,"Curabitur","mattis","nibh","ut","lorem","posuere","faucibus."},
{6,"Donec","hendrerit","eros","eget","turpis","blandit","interdum."},
{6,"Nam","vitae","arcu","in","quam","pretium","rutrum."},
{6,"Pellentesque","nec","mauris","ac","mauris","iaculis","gravida."},
{9,"Suspendisse","pharetra","velit","ac","lorem","sollicitudin,","at","posuere","nulla","dapibus."},
{9,"Ut","non","felis","ut","lorem","varius","condimentum","quis","a","eros."},
{6,"Nulla","convallis","quam","non","neque","aliquet","viverra."},
{9,"Integer","in","libero","rutrum","metus","aliquam","semper","quis","a","tortor."},
{6,"Nullam","id","odio","eget","mauris","ornare","gravida."},
{6,"Vivamus","vulputate","nisl","vel","tellus","volutpat","tincidunt."},
{7,"Praesent","fringilla","odio","sit","amet","enim","blandit","sodales."},
{5,"Suspendisse","suscipit","lectus","vel","bibendum","volutpat."},
{8,"Duis","et","metus","adipiscing,","convallis","odio","a,","venenatis","magna."},
{6,"Phasellus","vitae","urna","ac","eros","ultricies","pellentesque."},
{5,"Sed","consectetur","augue","nec","venenatis","vehicula."},
{9,"Nunc","euismod","dui","non","velit","pulvinar,","eget","volutpat","est","porta."},
{8,"Nullam","quis","sem","lacinia,","facilisis","arcu","non,","vulputate","mi."},
{9,"Duis","auctor","nulla","ut","justo","commodo,","tincidunt","euismod","dui","mollis."},
{6,"Vivamus","et","tortor","nec","lectus","vulputate","tempus."},
{9,"Nunc","id","dui","ut","magna","gravida","scelerisque","ac","non","risus."},
{6,"Proin","porta","nisl","vitae","neque","mollis","convallis."},
{5,"Aenean","dignissim","justo","vel","eleifend","mollis."},
{9,"Cras","et","enim","et","ligula","feugiat","dictum","ut","id","lorem."},
{9,"Aenean","cursus","turpis","ut","nisi","porttitor,","tristique","tempus","mi","adipiscing."},
{8,"Ut","ac","sapien","aliquet,","iaculis","enim","quis,","pellentesque","lorem."},
{9,"Fusce","id","diam","quis","libero","semper","sagittis","at","sed","justo."},
{6,"Nullam","vitae","justo","quis","ipsum","adipiscing","pulvinar."},
{6,"Proin","mollis","ipsum","non","nibh","condimentum","luctus."},
{6,"Praesent","fermentum","diam","et","lorem","consectetur","gravida."},
{8,"Fusce","facilisis","dolor","scelerisque,","accumsan","mauris","vel,","egestas","erat."},
{6,"Ut","convallis","tortor","vitae","magna","lobortis","molestie."},
{9,"Mauris","dignissim","mi","condimentum","lectus","mollis,","id","suscipit","mi","tristique."},
{8,"Integer","vehicula","lectus","dignissim,","pulvinar","quam","non,","semper","nisi."},
{8,"Sed","vitae","nulla","porttitor,","adipiscing","felis","quis,","pretium","magna."},
{9,"Donec","pellentesque","quam","at","diam","porttitor,","vel","mattis","lorem","placerat."},
{6,"Vivamus","imperdiet","est","quis","ligula","venenatis","molestie."},
{6,"Phasellus","dictum","nulla","et","felis","euismod","auctor."},
{6,"Integer","imperdiet","felis","vel","purus","vestibulum","aliquam."},
{9,"Fusce","suscipit","enim","vitae","elit","cursus,","id","pretium","sem","facilisis."},
};

static int errorCount = 0;

static void runTest()
{
	int i,j,status;
	int rangeErr[4];
	const char* word;

	printf("check that LSAddWord properly signals KWRANGEERROR\n");
	status = LSAddWord("");
	if (status != KWRANGEERROR) {
		printf("Error in LSAddWord return value.");
		printf(" Actual: %d Expected: %d\n",status,KWRANGEERROR);
		errorCount++;
	}

	printf("load lineList into LineStorage\n");
	for (i = 0; i < NUMLINES; i++) {
		printf("\tline %d\n",i);
		status = LSAddLine();
		if (status != KWSUCCESS) {
			printf("Error in LSAddLine return value.");
			printf(" Actual: %d Expected: %d\n",status,KWSUCCESS);
			errorCount++;
		}
		for (j = 0; j < lineList[i].numWords; j++) {
			printf("\t\tword %d\n",j);
			status = LSAddWord(lineList[i].wordList[j]);
			if (status != KWSUCCESS) {
				printf("Error in LSAddWord return value.");
				printf(" Actual: %d Expected: %d\n",
					status,KWSUCCESS);
				errorCount++;
			}
		}
	}

	printf("check that the lines have been properly stored\n");
	if (LSNumLines() != NUMLINES) {
		printf("Error in LSNumLines. Actual: %d Expected: %d\n",
			LSNumLines(),NUMLINES);
		errorCount++;
	}
	for (i = 0; i < NUMLINES; i++) {
		printf("\tline %d\n",i);
		if (LSNumWords(i) != lineList[i].numWords) {
			printf("Error in LSNumWord. Actual: %d Expected: %d\n",
				LSNumWords(i),lineList[i].numWords);
			errorCount++;
		}
		for (j = 0; j < lineList[i].numWords; j++) {
			printf("\t\tword %d\n",j);
			if (strcmp(LSGetWord(i,j),lineList[i].wordList[j])) {
				printf("Error in LSGetWords(%d,%d).",i,j);
				printf(" Actual: !%s! Expected: !%s!\n",
					LSGetWord(i,j),lineList[i].wordList[j]);
				errorCount++;
			}
		}
	}

	printf("check that line number range errors are properly signaled\n");
	rangeErr[0] = -1000;
	rangeErr[1] = -1;
	rangeErr[2] = NUMLINES;
	rangeErr[3] = NUMLINES+1000;
	for (i = 0; i < 4; i++) {
		printf("\tline %d\n",rangeErr[i]);
		status = LSNumWords(rangeErr[i]);
		if (status != KWRANGEERROR) {
			printf("Error in LSNumWords return value.");
			printf(" Actual: %d Expected: %d\n",
				status,KWRANGEERROR);
			errorCount++;
		}
		word = LSGetWord(rangeErr[i],0);
		if (word != 0) {
			printf("Error in LSGetWord return value.");
			printf(" Actual: !%s! Expected: %d\n",word,0);
			errorCount++;
		}
	}

	printf("check that word number range errors are properly signaled\n");
	rangeErr[0] = -1000;
	rangeErr[1] = -1;
	rangeErr[2] = lineList[0].numWords;
	rangeErr[3] = lineList[0].numWords+1000;
	for (i = 0; i < 4; i++) {
		printf("\tword %d\n",rangeErr[i]);
		word = LSGetWord(0,rangeErr[i]);
		if (word != 0) {
			printf("Error in LSGetWord return value.");
			printf(" Actual: !%s! Expected: %d\n",word,0);
			errorCount++;
		}
	}
}

int main()
{
	LSInit();

	printf("run the tests once\n");
	runTest();

	printf("check that LSReset runs without crashing\n");
	LSReset();

	printf("run the tests again\n");
	runTest();

	if (errorCount == 0)
		printf("\n\nNo errors detected!\n");
	return errorCount;
}
