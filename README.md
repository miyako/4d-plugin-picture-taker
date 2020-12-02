![platform](https://img.shields.io/static/v1?label=platform&message=osx-64&color=blue)
[![license](https://img.shields.io/github/license/miyako/4d-plugin-picture-taker)](LICENSE)
![downloads](https://img.shields.io/github/downloads/miyako/4d-plugin-picture-taker/total)

# 4d-plugin-picture-taker

Simple picture taker panel for macOS

4D implementation of [IKPictureTaker](https://developer.apple.com/documentation/quartz/ikpicturetaker?language=objc)

### Version

<img width="32" height="32" src="https://user-images.githubusercontent.com/1725068/73986501-15964580-4981-11ea-9ac1-73c5cee50aae.png"> <img src="https://user-images.githubusercontent.com/1725068/73987971-db2ea780-4984-11ea-8ada-e25fb9c3cf4e.png" width="32" height="32" />

See [ImageKit Programming Guide](https://developer.apple.com/library/content/documentation/GraphicsImaging/Conceptual/ImageKitProgrammingGuide/IKImagePicker/IKImagePicker.html) for more information.

## Syntax

```4d
DISPLAY PICTURE TAKER (picture{;options{;OK}})
```

Parameter|Type|Description
------------|------------|----
picture|PICTURE|default picture, picture taken
options|TEXT|options in JSON format; supported attributes are listed below
OK|LONGINT|``1`` if the dialog was validated


* Options

``showEffects`` (boolean)

``showRecentPicture`` (boolean)

``showAddressBookPicture`` (boolean)

``allowsVideoCapture`` (boolean)

``allowsFileChoosing`` (boolean)

``allowsEditing`` (boolean)

``updateRecentPicture`` (boolean)

``informationalText`` (text)

``cropAreaWidth`` (integer)

``cropAreaHeight`` (integer)

``outputImageMaxWidth`` (integer)

``outputImageMaxHeight`` (integer)


### Examples

```
C_PICTURE($picture)
READ PICTURE FILE(Get 4D folder(Current resources folder)+"4D.png";$picture)

C_OBJECT($options)
OB SET($options;"allowsEditing";False;"allowsFileChoosing";False)

DISPLAY PICTURE TAKER ($picture;JSON Stringify($options);$OK)

SET PICTURE TO PASTEBOARD($picture)
```
