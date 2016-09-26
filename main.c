#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"
#include <locale.h>

int		main()
{
	int ret1;
	int ret2;
	int	ret;
	char c;
	setlocale(LC_ALL, "");

	printf("TRUE :\n");
	ret = printf("%ld%ld", 0, 42);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%ld%ld", 0, 42);
	puts("");
	printf("ret1 : |%d|\n	", ret1);
	printf("===========================\n");

	printf("12C :\n");
	ret = printf("%ld", (long)INT_MAX + 1);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%ld", (long)INT_MAX + 1);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%ld", (long)INT_MIN - 1);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%ld", (long)INT_MIN - 1);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%ld", LONG_MAX);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%ld", LONG_MAX);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%ld", LONG_MIN);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%ld", LONG_MIN);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%li%li", 0, 42);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%li%li", 0, 42);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%li", (long)INT_MAX + 1);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%li", (long)INT_MAX + 1);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%li", (long)INT_MIN - 1);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%li", (long)INT_MIN - 1);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%li", LONG_MAX);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%li", LONG_MAX);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%li", LONG_MIN);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%li", LONG_MIN);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%lu, %lu", 0, ULONG_MAX);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%lu, %lu", 0, ULONG_MAX);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%lo, %lo", 0, ULONG_MAX);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%lo, %lo", 0, ULONG_MAX);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%lx, %lx", 0, ULONG_MAX);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%lx, %lx", 0, ULONG_MAX);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%lX, %lX", 0, ULONG_MAX);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%lX, %lX", 0, ULONG_MAX);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%lc, %lc", L'暖', L'ح');
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%lc, %lc", L'暖', L'ح');
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%ls, %ls", L"暖炉", L"لحم خنزير");
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%ls, %ls", L"暖炉", L"لحم خنزير");
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("Lorem %S ipsum dolor sit amet, consectetur adipiscing elit. Fusce tristique, velit imperdiet aliquam ultrices, erat est faucibus dolor, vel faucibus dolor tellus ac turpis. Quisque sollicitudin porttitor luctus. In id finibus sapien. Quisque eget felis sit amet nunc commodo interdum. Cras eleifend nibh vel erat interdum commodo. Nunc dapibus sem bibendum, scelerisque mauris in, condimentum felis. In sem metus, porta ac lectus quis, accumsan blandit tellus. Proin egestas felis vel tincidunt aliquam. Cras maximus dui sed mi bibendum, sed vulputate risus porttitor. Vivamus vel lectus sodales purus efficitur ultrices nec sit amet nisi.Quisque dapibus, orci sed tincidunt auctor, nibh diam rhoncus lorem, id luctus arcu dolor vitae mauris. Proin tincidunt, turpis id sodales malesuada, mi purus gravida risus, sit amet rutrum magna nunc laoreet purus. Nullam fermentum risus ut sapien elementum, quis mattis purus ullamcorper. Morbi lorem quam, rutrum eu sapien a, vulputate dapibus lacus. Vestibulum dignissim eu arcu ac sollicitudin. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aenean lobortis turpis quis velit posuere dictum. Suspendisse accumsan sem eget augue eleifend, eu consequat diam consequat. Sed laoreet rutrum sollicitudin. Duis et vulputate diam. Cras quis placerat mauris. Ut felis ligula, elementum eu dignissim nec, bibendum nec sapien. Aliquam auctor augue et lorem facilisis congue. Nunc et congue mi.Cras suscipit posuere accumsan. Interdum et malesuada fames ac ante ipsum primis in faucibus. Phasellus in lacinia tortor. Aenean sed diam purus. Nulla viverra luctus lorem vel ultrices. Vivamus nec lorem lobortis, vestibulum tortor eleifend, tempor magna. Vestibulum fringilla risus laoreet libero dapibus, at tristique ante mattis.Ut vulputate nisi sit amet mauris tristique, at mattis enim consequat. Phasellus mollis bibendum blandit. Maecenas pharetra est eu ultrices consectetur. Nam diam velit, finibus id tempus et, imperdiet a massa. Nam suscipit, ex ac vehicula ornare, lacus elit condimentum turpis, ac blandit velit est ut velit. Mauris aliquam commodo risus suscipit commodo. Aenean nec luctus ex, id hendrerit mi. Nam vitae convallis felis, non ultrices quam. Nunc vulputate aliquet felis at euismod. Phasellus et rhoncus tortor, sit amet sagittis tellus. In rutrum nisl lacus, vitae egestas arcu semper non.Integer suscipit et neque eget imperdiet. Pellentesque sollicitudin ligula vitae lobortis sollicitudin. Etiam non orci metus. Aenean auctor sodales aliquam. Vivamus bibendum at massa in pretium. Donec placerat velit ut viverra tempor. Suspendisse finibus enim ex, non ullamcorper ipsum posuere nec. Quisque nec sodales neque. Donec pharetra felis in erat vulputate mattis. Integer in est pellentesque lectus venenatis pharetra placerat ut felis. Vivamus iaculis eu turpis ac tincidunt. Donec ultricies quis tellus non volutpat.Quisque semper tempus condimentum. Nullam neque libero, hendrerit sed ornare in, aliquam sed enim. Donec viverra lacus quis fringilla molestie. Aliquam non dui ultricies, rutrum arcu tempor, varius nulla. Nullam vel porttitor odio. Aliquam nec erat arcu. Aliquam mattis massa non sodales viverra. Morbi quis sapien non ligula accumsan maximus. Sed sed tortor suscipit, eleifend tellus ac, luctus ipsum.Sed convallis urna quis elementum egestas. Proin et pharetra libero. Morbi elit mi, vehicula vitae tellus quis, finibus dictum velit. Aenean porta accumsan ligula, id venenatis justo tincidunt ac. Nullam sodales, turpis eu rhoncus accumsan, velit nibh condimentum massa, vel luctus felis turpis a nulla. Ut ullamcorper malesuada ipsum sit amet consectetur. Vestibulum vitae pellentesque diam. Integer vestibulum diam sed augue ultrices, eu maximus tortor lacinia. Morbi lacinia id augue vel porta. Mauris vel odio justo. Vivamus placerat vitae magna a consectetur. Aliquam facilisis ex sed nisi fermentum, vel porttitor elit elementum. Nulla congue vestibulum arcu, a consectetur nunc aliquam at. Fusce porttitor dapibus augue id semper.Maecenas %S tempus, nibh quis mattis pharetra, dolor elit convallis tellus, ac vestibulum arcu augue quis risus. Sed cursus hendrerit augue, quis dictum odio consectetur et. Donec sodales blandit justo et posuere. In auctor ut libero sed ultricies. Pellentesque ligula turpis, finibus laoreet magna id, iaculis ornare eros. Sed nec rhoncus dui, porta tincidunt elit. Sed at pharetra risus. Donec sollicitudin convallis ultrices. Nulla facilisi. Quisque a sodales ante. Duis ac ornare risus.Suspendisse potenti. Phasellus fringilla diam nec risus finibus congue. Cras facilisis velit ac tincidunt fermentum. Pellentesque quis est luctus, vulputate magna quis, lobortis justo. In id consequat orci. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam auctor lacus vitae lectus molestie pharetra. Ut nec vehicula magna, sodales pellentesque dui. Pellentesque malesuada vel nulla sed tristique. Phasellus odio augue, bibendum mattis dolor in, elementum iaculis augue. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Fusce sit amet aliquam odio. Mauris ut tortor quam. In sollicitudin non ante et vehicula. Sed at urna libero.Sed porttitor porta felis iaculis dignissim. Aliquam erat volutpat. Sed faucibus ultricies nunc et tincidunt. Nam fringilla dui at massa molestie, quis mollis mi vulputate. Nulla consectetur varius quam ac dignissim. Maecenas sed lobortis lacus. Integer ut volutpat arcu, eget varius arcu. Integer tristique sem a enim posuere facilisis. Morbi lobortis ligula eget tempor rhoncus. Suspendisse dapibus arcu arcu, eget accumsan dui rutrum id.Fusce interdum lectus varius ante pharetra sollicitudin. Cras nec arcu eu orci elementum dapibus vel eget justo. In malesuada quam elit, id consequat purus euismod at. Integer porta urna velit, at feugiat ipsum consequat sed. Duis ullamcorper porta orci eu consequat. Morbi sodales est eu dui sed.", L"ĈЄĈĪ Є$Ŧ ЦИ ŦЄXŦЄ ÐЄ ŦØЦ PØЦR ПØИ PRĪИŦŦ. ʖЄ $ЦĪ$ 42, ЄŦ ʖЄ $ЦĪ$ PRĪИŦŦ.", L"ⒿⒺ ⓈⓊⒾⓈ ⓊⓃⒺ ⒻⓊⒸⓀⒾⓃⒼ ⓅⒽⓇⒶⓈⒺ Ⓐ ⓂⒺⓉⓉⓇⒺ ⒺⓃ ⓅⓁⒺⒾⓃ ⓂⒾⓁⒾⒺⓊ ⒹⒺ ⓂⓄⓃ ⒷⓊⒻⒻⒺⓇ ⒺⓉ ⓄⓃ ⓋⒶ ⓋⓄⒾⓇ ⓈⒾ ⒸⒶ ⒻⒶⒾⓉ ⒸⒽⒾⒺ ⓄⓊ ⓅⒶⓈ.");
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("Lorem %S ipsum dolor sit amet, consectetur adipiscing elit. Fusce tristique, velit imperdiet aliquam ultrices, erat est faucibus dolor, vel faucibus dolor tellus ac turpis. Quisque sollicitudin porttitor luctus. In id finibus sapien. Quisque eget felis sit amet nunc commodo interdum. Cras eleifend nibh vel erat interdum commodo. Nunc dapibus sem bibendum, scelerisque mauris in, condimentum felis. In sem metus, porta ac lectus quis, accumsan blandit tellus. Proin egestas felis vel tincidunt aliquam. Cras maximus dui sed mi bibendum, sed vulputate risus porttitor. Vivamus vel lectus sodales purus efficitur ultrices nec sit amet nisi.Quisque dapibus, orci sed tincidunt auctor, nibh diam rhoncus lorem, id luctus arcu dolor vitae mauris. Proin tincidunt, turpis id sodales malesuada, mi purus gravida risus, sit amet rutrum magna nunc laoreet purus. Nullam fermentum risus ut sapien elementum, quis mattis purus ullamcorper. Morbi lorem quam, rutrum eu sapien a, vulputate dapibus lacus. Vestibulum dignissim eu arcu ac sollicitudin. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aenean lobortis turpis quis velit posuere dictum. Suspendisse accumsan sem eget augue eleifend, eu consequat diam consequat. Sed laoreet rutrum sollicitudin. Duis et vulputate diam. Cras quis placerat mauris. Ut felis ligula, elementum eu dignissim nec, bibendum nec sapien. Aliquam auctor augue et lorem facilisis congue. Nunc et congue mi.Cras suscipit posuere accumsan. Interdum et malesuada fames ac ante ipsum primis in faucibus. Phasellus in lacinia tortor. Aenean sed diam purus. Nulla viverra luctus lorem vel ultrices. Vivamus nec lorem lobortis, vestibulum tortor eleifend, tempor magna. Vestibulum fringilla risus laoreet libero dapibus, at tristique ante mattis.Ut vulputate nisi sit amet mauris tristique, at mattis enim consequat. Phasellus mollis bibendum blandit. Maecenas pharetra est eu ultrices consectetur. Nam diam velit, finibus id tempus et, imperdiet a massa. Nam suscipit, ex ac vehicula ornare, lacus elit condimentum turpis, ac blandit velit est ut velit. Mauris aliquam commodo risus suscipit commodo. Aenean nec luctus ex, id hendrerit mi. Nam vitae convallis felis, non ultrices quam. Nunc vulputate aliquet felis at euismod. Phasellus et rhoncus tortor, sit amet sagittis tellus. In rutrum nisl lacus, vitae egestas arcu semper non.Integer suscipit et neque eget imperdiet. Pellentesque sollicitudin ligula vitae lobortis sollicitudin. Etiam non orci metus. Aenean auctor sodales aliquam. Vivamus bibendum at massa in pretium. Donec placerat velit ut viverra tempor. Suspendisse finibus enim ex, non ullamcorper ipsum posuere nec. Quisque nec sodales neque. Donec pharetra felis in erat vulputate mattis. Integer in est pellentesque lectus venenatis pharetra placerat ut felis. Vivamus iaculis eu turpis ac tincidunt. Donec ultricies quis tellus non volutpat.Quisque semper tempus condimentum. Nullam neque libero, hendrerit sed ornare in, aliquam sed enim. Donec viverra lacus quis fringilla molestie. Aliquam non dui ultricies, rutrum arcu tempor, varius nulla. Nullam vel porttitor odio. Aliquam nec erat arcu. Aliquam mattis massa non sodales viverra. Morbi quis sapien non ligula accumsan maximus. Sed sed tortor suscipit, eleifend tellus ac, luctus ipsum.Sed convallis urna quis elementum egestas. Proin et pharetra libero. Morbi elit mi, vehicula vitae tellus quis, finibus dictum velit. Aenean porta accumsan ligula, id venenatis justo tincidunt ac. Nullam sodales, turpis eu rhoncus accumsan, velit nibh condimentum massa, vel luctus felis turpis a nulla. Ut ullamcorper malesuada ipsum sit amet consectetur. Vestibulum vitae pellentesque diam. Integer vestibulum diam sed augue ultrices, eu maximus tortor lacinia. Morbi lacinia id augue vel porta. Mauris vel odio justo. Vivamus placerat vitae magna a consectetur. Aliquam facilisis ex sed nisi fermentum, vel porttitor elit elementum. Nulla congue vestibulum arcu, a consectetur nunc aliquam at. Fusce porttitor dapibus augue id semper.Maecenas %S tempus, nibh quis mattis pharetra, dolor elit convallis tellus, ac vestibulum arcu augue quis risus. Sed cursus hendrerit augue, quis dictum odio consectetur et. Donec sodales blandit justo et posuere. In auctor ut libero sed ultricies. Pellentesque ligula turpis, finibus laoreet magna id, iaculis ornare eros. Sed nec rhoncus dui, porta tincidunt elit. Sed at pharetra risus. Donec sollicitudin convallis ultrices. Nulla facilisi. Quisque a sodales ante. Duis ac ornare risus.Suspendisse potenti. Phasellus fringilla diam nec risus finibus congue. Cras facilisis velit ac tincidunt fermentum. Pellentesque quis est luctus, vulputate magna quis, lobortis justo. In id consequat orci. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam auctor lacus vitae lectus molestie pharetra. Ut nec vehicula magna, sodales pellentesque dui. Pellentesque malesuada vel nulla sed tristique. Phasellus odio augue, bibendum mattis dolor in, elementum iaculis augue. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Fusce sit amet aliquam odio. Mauris ut tortor quam. In sollicitudin non ante et vehicula. Sed at urna libero.Sed porttitor porta felis iaculis dignissim. Aliquam erat volutpat. Sed faucibus ultricies nunc et tincidunt. Nam fringilla dui at massa molestie, quis mollis mi vulputate. Nulla consectetur varius quam ac dignissim. Maecenas sed lobortis lacus. Integer ut volutpat arcu, eget varius arcu. Integer tristique sem a enim posuere facilisis. Morbi lobortis ligula eget tempor rhoncus. Suspendisse dapibus arcu arcu, eget accumsan dui rutrum id.Fusce interdum lectus varius ante pharetra sollicitudin. Cras nec arcu eu orci elementum dapibus vel eget justo. In malesuada quam elit, id consequat purus euismod at. Integer porta urna velit, at feugiat ipsum consequat sed. Duis ullamcorper porta orci eu consequat. Morbi sodales est eu dui sed.", L"ĈЄĈĪ Є$Ŧ ЦИ ŦЄXŦЄ ÐЄ ŦØЦ PØЦR ПØИ PRĪИŦŦ. ʖЄ $ЦĪ$ 42, ЄŦ ʖЄ $ЦĪ$ PRĪИŦŦ.", L"ⒿⒺ ⓈⓊⒾⓈ ⓊⓃⒺ ⒻⓊⒸⓀⒾⓃⒼ ⓅⒽⓇⒶⓈⒺ Ⓐ ⓂⒺⓉⓉⓇⒺ ⒺⓃ ⓅⓁⒺⒾⓃ ⓂⒾⓁⒾⒺⓊ ⒹⒺ ⓂⓄⓃ ⒷⓊⒻⒻⒺⓇ ⒺⓉ ⓄⓃ ⓋⒶ ⓋⓄⒾⓇ ⓈⒾ ⒸⒶ ⒻⒶⒾⓉ ⒸⒽⒾⒺ ⓄⓊ ⓅⒶⓈ.");
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%lc", 12542);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%lc", 12542);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%lc", 12542698487);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%lc", 12542698487);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 0xFFFF);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 0xFFFF);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 0x00);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 0x00);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 0xFFFE);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 0xFFFE);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 0xFFFFF);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 0xFFFFF);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 0xD800);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 0xD800);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 0xD7FF); // 0xD800 - 1
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 0xD7FF);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");


	printf("TRUE :\n");
	ret = printf("%C", 57343); // 0xDFFF
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 57343);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 0xE000); // 0xDFFF + 1
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 0xE000);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 57400);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 57400);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", L'');
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", L'');
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 63743);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 63743);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%.C", L'ê');
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%.C", L'ê');
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%.C", 1);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%.C", 1);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%.C", 0);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%.C", 0);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%.C", -1);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%.C", -1);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%.C", 1114111);
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%.C", 1114111);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", -'a');
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", -'a');
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("TRUE :\n");
	ret = printf("%C", 'a');
	puts("");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret1 = ft_printf("%C", 'a');
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("MINE :\n");
	ret1 = ft_printf("%b", 10);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("MINE :\n");
	ret1 = ft_printf("%b", 0);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("MINE :\n");
	ret1 = ft_printf("%b", -10);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	printf("MINE :\n");
	ret1 = ft_printf("%5b", 1);
	puts("");
	printf("ret1 : |%d|\n", ret1);
	printf("===========================\n");

	return (0);

}