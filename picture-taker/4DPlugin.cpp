/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : Picture Taker
 #	author : miyako
 #	2017/06/19
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

void PluginMain(PA_long32 selector, PA_PluginParameters params)
{
	try
	{
		PA_long32 pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		CommandDispatcher(pProcNum, pResult, pParams); 
	}
	catch(...)
	{

	}
}

void CommandDispatcher (PA_long32 pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{
	switch(pProcNum)
	{
// --- Picture Taker

		case 1 :
			DISPLAY_PICTURE_TAKER(pResult, pParams);
			break;

	}
}

// --------------------------------- Picture Taker --------------------------------

#pragma mark JSON

#pragma mark -

void _DISPLAY_PICTURE_TAKER(PackagePtr pParams)
{
	IKPictureTaker *pictureTaker = [IKPictureTaker pictureTaker];
	[pictureTaker setMirroring:YES];
	[pictureTaker setInputImage:nil];
	
	PA_Picture Param1 = *(PA_Picture *)(pParams[0]);
	CGImageRef ci = (CGImageRef)PA_CreateNativePictureForScreen(Param1);
	if(ci)
	{
		NSImage *ni = [[NSImage alloc]initWithCGImage:ci size:NSZeroSize];
		[pictureTaker setInputImage:ni];
		CFRelease(ci);
		[ni release];
	}

	C_TEXT Param2;
	Param2.fromParamAtIndex(pParams, 2);
    
    CUTF8String Param2_u8;
    Param2.copyUTF8String(&Param2_u8);
    
    Json::Value root;
    Json::CharReaderBuilder builder;
    std::string errors;
    
    Json::CharReader *reader = builder.newCharReader();
    bool parse = reader->parse((const char *)Param2_u8.c_str(),
                               (const char *)Param2_u8.c_str() + Param2_u8.size(),
                               &root,
                               &errors);
    
    delete reader;
    
    if(parse)
    {
        if(root.isObject())
        {
            IKPictureTaker *pictureTaker = [IKPictureTaker pictureTaker];

            //default:YES
            
            Json::Value allowsVideoCapture = root["allowsVideoCapture"];
            if(allowsVideoCapture.isBool()) {
                [pictureTaker setValue:[NSNumber numberWithBool:allowsVideoCapture.asBool()]
                                forKey:IKPictureTakerAllowsVideoCaptureKey];
            }
            
            Json::Value allowsFileChoosing = root["allowsFileChoosing"];
            if(allowsFileChoosing.isBool()) {
                [pictureTaker setValue:[NSNumber numberWithBool:allowsFileChoosing.asBool()]
                                forKey:IKPictureTakerAllowsFileChoosingKey];
            }
            
            Json::Value showRecentPicture = root["showRecentPicture"];
            if(showRecentPicture.isBool()) {
                [pictureTaker setValue:[NSNumber numberWithBool:showRecentPicture.asBool()]
                                forKey:IKPictureTakerShowRecentPictureKey];
            }
            
            Json::Value updateRecentPicture = root["updateRecentPicture"];
            if(updateRecentPicture.isBool()) {
                [pictureTaker setValue:[NSNumber numberWithBool:updateRecentPicture.asBool()]
                                forKey:IKPictureTakerUpdateRecentPictureKey];
            }
            
            Json::Value allowsEditing = root["allowsEditing"];
            if(allowsEditing.isBool()) {
                [pictureTaker setValue:[NSNumber numberWithBool:allowsEditing.asBool()]
                                forKey:IKPictureTakerAllowsEditingKey];
            }
            
            //default:NO
            
            Json::Value showEffects = root["showEffects"];
            if(showEffects.isBool()) {
                [pictureTaker setValue:[NSNumber numberWithBool:showEffects.asBool()]
                                forKey:IKPictureTakerShowEffectsKey];
            }
            
            Json::Value showAddressBookPicture = root["showAddressBookPicture"];
            if(showAddressBookPicture.isBool()) {
                [pictureTaker setValue:[NSNumber numberWithBool:showAddressBookPicture.asBool()]
                                forKey:IKPictureTakerShowAddressBookPictureKey];
            }
            
            //
            
            Json::Value cropAreaWidth = root["cropAreaWidth"];
            Json::Value cropAreaHeight = root["cropAreaHeight"];
            if((cropAreaWidth.isNumeric()) && (cropAreaHeight.isNumeric())) {
                [pictureTaker setValue:[NSValue valueWithSize:NSMakeSize(cropAreaWidth.asInt(), cropAreaHeight.asInt())]
                                forKey:IKPictureTakerCropAreaSizeKey];//deprecated
            }
            
            Json::Value outputImageMaxWidth = root["outputImageMaxWidth"];
            Json::Value outputImageMaxHeight = root["outputImageMaxHeight"];
            if((outputImageMaxWidth.isNumeric()) && (outputImageMaxHeight.isNumeric())) {
                [pictureTaker setValue:[NSValue valueWithSize:NSMakeSize(outputImageMaxWidth.asInt(), outputImageMaxHeight.asInt())]
                                forKey:IKPictureTakerOutputImageMaxSizeKey];
            }
        }
    }
    
	C_LONGINT Param3;
	Param3.fromParamAtIndex(pParams, 3);
	
	switch([pictureTaker runModal])
	{
		case NSOKButton:
		{
			NSImage *ni = [pictureTaker outputImage];
			if(ni)
			{
				NSData *imageData = [ni TIFFRepresentation];
				if(imageData)
				{
					PA_Picture *ptpict = ((PA_Picture*)pParams[0]);
					if (*ptpict) PA_DisposePicture(*ptpict);
					*ptpict = PA_CreatePicture((void *)[imageData bytes], (PA_long32)[imageData length]);
				}
			}
			Param3.setIntValue(1);
		}
			break;
		default:
			break;
	}
	Param3.toParamAtIndex(pParams, 3);
}

void DISPLAY_PICTURE_TAKER(sLONG_PTR *pResult, PackagePtr pParams)
{
	PA_RunInMainProcess((PA_RunInMainProcessProcPtr)_DISPLAY_PICTURE_TAKER, pParams);
}

