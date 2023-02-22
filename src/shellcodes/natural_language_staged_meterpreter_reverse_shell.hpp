#define LEN 510

std::string key[256] = {"poeticalness","allergology","formes","heartfully","desperadoism","conchfishes","nontolerably","ceroplastics","aprication","secretarian","cibarium","greund","capitaled","clowring","canicule","trichogen","retia","televiewed","subretractile","unmeddled","pukes","unbraveness","acetabuliform","connochaetes","humiria","indicting","rebuttoned","allolalia","demonastery","disciplinarity","virose","nonorally","interpelling","condescent","preoccurring","feckless","thermotensile","scrubwoman","unhele","hydrotherapeutically","journeyman","signor","strumpet","bad","glossata","quantifications","gleams","trending","mistakenness","swooner","nondepreciatory","bioelectrogenetically","lapins","pinkwood","pettifogging","hexacosane","hypogenous","atmolyzation","yaks","falsism","nonissuable","digitigradism","reflies","kerosene","unbetraying","bandwidths","tulip","waffles","professorate","polycrystalline","interacting","unrack","elongating","sostinente","disjointedly","trespasses","suicides","unliveably","unpassive","bankbook","dearths","disrange","cogitate","resew","gloriana","caponette","catchweed","ditheisms","molestful","damascener","antidogmatist","vulsinite","apothec","martyrisation","essancia","alcumy","fablemonger","murmurlessly","packplane","pawnshops","maitre","nonrevocation","interadaption","quarentene","soberized","blowout","grieffully","initialist","sentried","beblubber","expective","comparers","ruesomeness","trouse","ovovitellin","pyranose","radioastronomy","biometer","dermahemia","allegiantly","cynocephalus","unexcelled","oleaceous","sitta","relanced","autogamic","sexennium","sphygmoscope","ophthalitis","animatistic","flail","timaeus","militia","ensuing","unquieted","cardiograms","filibranch","hymenomycetal","fruitfullest","nathe","kamseens","precipitately","breechloading","perkingly","showboating","subessential","isocephalism","superperfection","yachty","assents","sideness","collybist","sterelminthic","unmeddlingness","eucharis","unassociativeness","stunsail","isomerization","squary","sunbathe","waldflute","laroid","nonportability","politer","peyton","saginate","slodge","climatotherapeutics","grubstaking","arefact","towermen","phenoxazine","supersecularly","pidjajap","wandlike","reinforce","blindcat","appendaged","catapan","unintricately","amination","dishabilitation","bialveolar","correlated","decarbonylating","planorbine","illegalness","raiment","irade","sacope","autem","slabbered","believing","marishes","encroaches","dimuence","arboroid","kenningwort","avosets","superadds","peronate","klatsch","gossipdom","productibility","chalcidiform","sufficing","almadie","chinse","diaschisis","balanidae","preadjectival","brunoniaceae","unforbade","scratchily","cimolite","rugosely","exhorting","pannus","federate","wreat","mashier","tacheography","twi","splashdowns","demonstrator","antwise","unnormalness","pseudoscines","instate","ambient","exogamies","plurimammate","repenning","aldebaran","unerroneously","qv","serines","player","awol","masulipatam","podsols","remembered","pinkweed","footgeld","resatisfaction","nonsuffrage","doughbird","applicators","retailment","strowed","ashraf","spaniardize","ergotizing","calibrations","teetotalers","impetiginous",};

std::string encrypted[510] = {"ergotizing","elongating","timaeus","instate","podsols","repenning","chalcidiform","poeticalness","poeticalness","poeticalness","bandwidths","disrange","bandwidths","dearths","cogitate","elongating","swooner","preadjectival","disrange","catchweed","nonrevocation","elongating","nathe","cogitate","fablemonger","elongating","nathe","cogitate","humiria","elongating","nathe","cogitate","interpelling","elongating","trichogen","correlated","disjointedly","disjointedly","elongating","nathe","ovovitellin","dearths","unliveably","swooner","klatsch","elongating","swooner","believing","supersecularly","nonissuable","murmurlessly","relanced","formes","glossata","interpelling","bandwidths","marishes","klatsch","clowring","bandwidths","allergology","marishes","unnormalness","player","cogitate","elongating","nathe","cogitate","interpelling","nathe","tulip","nonissuable","elongating","allergology","diaschisis","bandwidths","disrange","interadaption","animatistic","cynocephalus","humiria","greund","formes","trichogen","ensuing","ovovitellin","poeticalness","poeticalness","poeticalness","nathe","ophthalitis","filibranch","poeticalness","poeticalness","poeticalness","elongating","ensuing","believing","radioastronomy","quarentene","elongating","allergology","diaschisis","professorate","nathe","unbetraying","interpelling","dearths","sostinente","allergology","diaschisis","nathe","elongating","humiria","pseudoscines","catchweed","unliveably","swooner","klatsch","elongating","impetiginous","klatsch","bandwidths","nathe","lapins","filibranch","elongating","allergology","cimolite","elongating","swooner","believing","bandwidths","marishes","klatsch","clowring","supersecularly","bandwidths","allergology","marishes","hypogenous","demonstrator","biometer","remembered","suicides","heartfully","suicides","thermotensile","aprication","polycrystalline","atmolyzation","balanidae","biometer","exhorting","molestful","professorate","nathe","unbetraying","thermotensile","sostinente","allergology","diaschisis","interadaption","bandwidths","nathe","capitaled","elongating","professorate","nathe","unbetraying","demonastery","sostinente","allergology","diaschisis","bandwidths","nathe","desperadoism","filibranch","elongating","allergology","diaschisis","bandwidths","molestful","bandwidths","molestful","essancia","damascener","antidogmatist","bandwidths","molestful","bandwidths","damascener","bandwidths","antidogmatist","elongating","timaeus","serines","interpelling","bandwidths","cogitate","impetiginous","demonstrator","molestful","bandwidths","damascener","antidogmatist","elongating","nathe","subretractile","aldebaran","trespasses","impetiginous","impetiginous","impetiginous","martyrisation","sostinente","autem","allegiantly","pyranose","nondepreciatory","alcumy","bioelectrogenetically","nondepreciatory","poeticalness","poeticalness","bandwidths","catchweed","sostinente","hymenomycetal","exogamies","elongating","animatistic","serines","waldflute","allergology","poeticalness","poeticalness","sostinente","hymenomycetal","ambient","sostinente","irade","formes","poeticalness","nonorally","showboating","believing","grubstaking","televiewed","ensuing","bandwidths","gloriana","sostinente","hymenomycetal","instate","suicides","hymenomycetal","remembered","bandwidths","illegalness","suicides","allegiantly","unhele","ceroplastics","impetiginous","scratchily","suicides","hymenomycetal","unerroneously","soberized","allergology","allergology","poeticalness","poeticalness","damascener","bandwidths","illegalness","signor","ophthalitis","initialist","poeticalness","impetiginous","scratchily","grieffully","cibarium","bandwidths","essancia","dearths","dearths","unliveably","swooner","klatsch","unliveably","swooner","believing","elongating","impetiginous","believing","elongating","hymenomycetal","encroaches","elongating","impetiginous","believing","elongating","hymenomycetal","marishes","bandwidths","illegalness","unerroneously","trichogen","splashdowns","demonstrator","impetiginous","scratchily","elongating","hymenomycetal","superadds","grieffully","retia","bandwidths","molestful","suicides","hymenomycetal","unnormalness","elongating","hymenomycetal","strowed","bandwidths","illegalness","unmeddlingness","saginate","radioastronomy","murmurlessly","impetiginous","scratchily","ensuing","believing","radioastronomy","cibarium","sostinente","impetiginous","almadie","biometer","ambient","repenning","superperfection","poeticalness","poeticalness","poeticalness","elongating","timaeus","serines","retia","elongating","hymenomycetal","unnormalness","unliveably","swooner","klatsch","grieffully","desperadoism","bandwidths","molestful","elongating","hymenomycetal","strowed","bandwidths","illegalness","formes","pannus","peronate","alcumy","impetiginous","scratchily","timaeus","retailment","poeticalness","sexennium","caponette","elongating","timaeus","arboroid","interpelling","essancia","hymenomycetal","doughbird","grieffully","unbetraying","bandwidths","damascener","soberized","poeticalness","retia","poeticalness","poeticalness","bandwidths","molestful","elongating","hymenomycetal","pinkweed","elongating","swooner","klatsch","bandwidths","illegalness","molestful","peyton","resew","ambient","impetiginous","scratchily","elongating","hymenomycetal","dimuence","sostinente","hymenomycetal","superadds","unliveably","swooner","klatsch","sostinente","hymenomycetal","podsols","elongating","hymenomycetal","federate","elongating","hymenomycetal","strowed","bandwidths","illegalness","formes","pannus","peronate","alcumy","impetiginous","scratchily","timaeus","retailment","poeticalness","autogamic","journeyman","molestful","bandwidths","ditheisms","damascener","soberized","poeticalness","unbetraying","poeticalness","poeticalness","bandwidths","molestful","grieffully","poeticalness","antidogmatist","bandwidths","illegalness","greund","trending","trichogen","mistakenness","impetiginous","scratchily","ditheisms","damascener","bandwidths","illegalness","biometer","expective","unliveably","murmurlessly","impetiginous","scratchily","sostinente","impetiginous","almadie","aldebaran","nonissuable","impetiginous","impetiginous","impetiginous","elongating","allergology","dimuence","elongating","signor","avosets","elongating","ensuing","doughbird","biometer","amination","bandwidths","impetiginous","plurimammate","molestful","grieffully","poeticalness","damascener","sostinente","superadds","encroaches","podsols","dishabilitation","nonportability","catchweed","impetiginous","scratchily",};
